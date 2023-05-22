class ArrayWrapper {
    private _nums: number[]

    constructor(nums: number[]) {
        this._nums = nums
    }

    valueOf() {
        return this._nums.reduce((sum, cur) => sum + cur, 0)
    }

    toString() {
        return `[${this._nums}]`;
    }
};