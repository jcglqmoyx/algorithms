function chunk(arr: any[], size: number): any[][] {
    const ans = Array(Math.round(arr.length / size));
    let i = 0, start = 0, end = size;
    while (start < arr.length) {
        ans[i++] = arr.slice(start, end);
        start = end;
        end += size;
    }
    return ans;
};