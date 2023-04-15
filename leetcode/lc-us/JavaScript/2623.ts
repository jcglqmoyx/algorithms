type Fn = (...params: any) => any

function memoize(fn: Fn): Fn {
    const cache = new Map<string, unknown>()
    return function (...args) {
        const key = args.join('#')
        if (cache.has(key)) return cache.get(key)
        const res = fn.apply(this, args)
        cache.set(key, res)
        return res
    }
}