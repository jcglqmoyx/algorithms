type F = () => Promise<unknown>

function promisePool(functions: F[], n: number): Promise<unknown> {
    const res: unknown[] = []
    const iter = functions.entries()
    const workers = Array(n).fill(iter).map(work)
    return Promise.all(workers).then(() => res)

    async function work(entries: IterableIterator<[number, F]>) {
        for (const [index, task] of entries) {
            // eslint-disable-next-line no-await-in-loop
            const cur = await task()
            res[index] = cur
        }
    }
}