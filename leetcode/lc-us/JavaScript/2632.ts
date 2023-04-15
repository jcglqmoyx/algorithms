function curry(fn: Function): Function {
    return function curried(...args: any[]) {
        if (args.length >= fn.length) {
            return fn(...args);
        } else {
            return function (...nextArgs: any[]) {
                return curried(...args, ...nextArgs);
            };
        }
    };
};

function sum(a: number, b: number): number {
    return a + b;
}