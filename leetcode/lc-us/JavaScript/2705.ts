const isObject = (val: unknown): val is object => typeof val === "object" && val !== null;
const isArray = Array.isArray;

type Obj = Record<any, any>;

function compactObject(obj: Obj): Obj {
    let result: Obj;
    if (isArray(obj)) {
        result = [];
        for (const value of obj) {
            if (isObject(value)) {
                result.push(compactObject(value));
            } else if (value) {
                result.push(value);
            }
        }
    } else {
        result = {};
        const keys = Object.keys(obj);
        for (const key of keys) {
            const value = obj[key];
            if (isObject(value)) {
                result[key] = compactObject(value);
            } else if (value) {
                result[key] = value;
            }
        }
    }

    return result;
}