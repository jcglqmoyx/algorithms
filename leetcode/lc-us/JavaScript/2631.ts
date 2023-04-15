declare global {
    interface Array<T> {
        groupBy(fn: (item: T) => string): Record<string, T[]>
    }
}

Array.prototype.groupBy = function (fn) {
    return this.reduce((ans, e) => {
        const key = fn(e);

        if (key in ans) {
            ans[key].push(e);
        } else ans[key] = [e];

        return ans;
    }, {});
}