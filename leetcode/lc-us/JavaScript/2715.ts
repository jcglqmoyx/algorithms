function cancellable(fn: Function, args: any[], t: number): Function {

    const timer = setTimeout(() => {
        fn.apply(null, args);
    }, t);

    return () => {
        clearTimeout(timer);
    }

};