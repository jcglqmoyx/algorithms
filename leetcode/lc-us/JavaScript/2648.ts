function* fibGenerator(): Generator<number, any, number> {
    let a = 0, b = 1
    while (true) {
        yield a
        b += a
        a = b - a
    }
};