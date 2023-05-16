function once<T extends (...args: any[]) => any>(
    fn: T
): (...args: Parameters<T>) => ReturnType<T> | undefined {
    let used = false;
    return (...args) => used ? undefined : (used = true, fn(...args));
}