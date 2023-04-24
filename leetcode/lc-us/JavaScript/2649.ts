type MultidimensionalArray = (MultidimensionalArray | number)[]

function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
    // 注意这里不能直接扁平化数组，生成器的作用就是用到了再取值
    for (let i = 0; i < arr.length; i++) {
        let cur = arr[i]
        if (Array.isArray(cur)) {
            yield* inorderTraversal(cur)
        } else {
            yield cur
        }
    }
};