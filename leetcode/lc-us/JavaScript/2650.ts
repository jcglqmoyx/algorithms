function isPromise<T>(obj: any): obj is Promise<Awaited<T>> {
    return typeof obj?.then === 'function'
}

function cancellable<T>(
    generator: Generator<Promise<any>, T, unknown>,
): [() => void, Promise<T>] {
    let isCanceled = false
    const cancel = () => {
        isCanceled = true
    }
    const task = new Promise<T>(async (resolve, reject) => {
        let value: unknown
        let done: boolean | undefined
        let inError = false
        let error: unknown
        while (true) {
            if (isCanceled) {
                inError = true
                error = 'Cancelled'
            }
            try {
                if (inError) {
                    ;({value, done} = generator.throw(error))
                    inError = false
                    error = null
                } else {
                    ;({value, done} = generator.next(value))
                }
            } catch (err) {
                reject(err)
                return
            }
            if (done) {
                resolve(value as T)
                return
            }
            if (isPromise<T>(value)) {
                try {
                    value = await value
                } catch (err) {
                    inError = true
                    error = err
                }
            }
        }
    })
    return [cancel, task]
}