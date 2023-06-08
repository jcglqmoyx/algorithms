type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

function throwError(msg: string): never {
    throw new Error(msg);
}

function expect(val1: any): ToBeOrNotToBe {
    return {
        toBe: val2 => (val1 === val2 ? true : throwError('Not Equal')),
        notToBe: val2 => (val1 !== val2 ? true : throwError('Equal')),
    };
}