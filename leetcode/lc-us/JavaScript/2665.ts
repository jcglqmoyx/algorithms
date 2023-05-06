type ReturnObj = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number): ReturnObj {
    let memoValue = init

    return {
        increment: () => ++memoValue,
        decrement: () => --memoValue,
        reset: () => memoValue = init,
    }
};