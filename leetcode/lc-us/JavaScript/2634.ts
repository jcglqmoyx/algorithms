function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    let res: number[] = []
    for (let i = 0; i < arr.length; i++) {
        if (fn(arr[i], i)) {
            res.push(arr[i])
        }
    }
    return res
};