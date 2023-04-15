function jsonStringify(object: any): string {
    if (object === null) {
        return 'null';
    }
    if (typeof object === 'string') {
        return '"' + object + '"';
    }
    if (typeof object === 'number' || typeof object === 'boolean') {
        return object.toString();
    }

    if (Array.isArray(object)) {
        let arrayStr = '[';
        for (let i = 0; i < object.length; i++) {
            arrayStr += jsonStringify(object[i]);
            if (i < object.length - 1) {
                arrayStr += ',';
            }
        }
        arrayStr += ']';
        return arrayStr;
    }

    let objStr = '{';
    const keys = Object.keys(object);
    for (let i = 0; i < keys.length; i++) {
        const key = keys[i];
        objStr += '"' + key + '":' + jsonStringify(object[key]);
        if (i < keys.length - 1) {
            objStr += ',';
        }
    }
    objStr += '}';
    return objStr;
}