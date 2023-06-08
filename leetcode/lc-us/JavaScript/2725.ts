function cancellable(fn: Function, args: any[], t: number): Function {
    let cancel = false;
    const interval = () => {
        fn(...args);
        if (!cancel) {
            setTimeout(() => interval(), t);
        }
    };

    interval();

    return () => (cancel = true);
}