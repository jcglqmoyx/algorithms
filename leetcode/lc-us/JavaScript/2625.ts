type MultiDimensionalArray = (number | MultiDimensionalArray)[];

function* inorder(arr: MultiDimensionalArray, n: number) {
    // depth limit reached
    if (n < 0) {
        yield arr;
        return;
    }

    // recursively DFS
    for (const val of arr) {
        if (typeof val === 'number') {
            yield val;
        } else {
            yield* inorder(val, n - 1);
        }
    }
}

var flat = function (arr: MultiDimensionalArray, n: number): MultiDimensionalArray {
    return [...inorder(arr, n)];
};