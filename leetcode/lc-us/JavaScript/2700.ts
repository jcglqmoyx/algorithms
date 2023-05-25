function objDiff(obj1: any, obj2: any): any {
    if (check(obj1) != check(obj2)) return [obj1, obj2]
    let ans: object = {}
    for (let key in obj1) {
        if (obj2.hasOwnProperty(key)) {
            if (check(obj1[key]) != check(obj2[key])) {
                ans[key] = [obj1[key], obj2[key]]
            } else {
                if (obj1[key] instanceof Object && obj2[key] instanceof Object) {
                    let val = objDiff(obj1[key], obj2[key])
                    if (Object.keys(val).length) {
                        ans[key] = val
                    }
                } else if (obj1[key] != obj2[key]) {
                    ans[key] = [obj1[key], obj2[key]]
                }
            }
        }
    }
    return ans
};

function check(data: any): string {
    let res = Object.prototype.toString.call(data).split(' ')[1]
    return res.substring(0, res.length - 1).toLowerCase()
}