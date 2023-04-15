class TimeLimitedCache {
    private readonly _cache: Map<number, [value: number, expired: number]> = new Map()

    set(key: number, value: number, duration: number): boolean {
        this._expire()
        const res = this._cache.has(key)
        const now = Date.now()
        this._cache.set(key, [value, now + duration])
        return res
    }

    get(key: number): number {
        this._expire()
        if (!this._cache.has(key)) return -1
        return this._cache.get(key)![0]
    }

    count(): number {
        this._expire()
        return this._cache.size
    }

    private _expire(): void {
        const now = Date.now()
        this._cache.forEach((value, key) => {
            if (value[1] <= now) this._cache.delete(key)
        })
    }
}