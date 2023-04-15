type Fn = (...params: any) => any

type CacheMap = Map<any, CacheItem>;
type CacheItem = { value?: any, next?: CacheMap };

function memoize(fn: Fn): Fn {
    const rootItem: CacheItem = {};

    return function (...args: any[]): any {
        let item: CacheItem | undefined = rootItem;

        for (const arg of args) {
            const map = item.next ??= new Map();
            item = map.get(arg);

            if (item == null) {
                map.set(arg, item = {});
            }
        }

        if ("value" in item) {
            return item.value;
        }

        return item.value = fn(...args);
    }
}