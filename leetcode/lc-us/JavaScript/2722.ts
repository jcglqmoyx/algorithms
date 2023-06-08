function join(arr1: any[], arr2: any[]): any[] {
    const m = new Map(arr1.map(x => [x.id, x]));
    arr2.forEach(x => {
        if (m.has(x.id)) {
            const y = m.get(x.id);
            m.set(x.id, {...y, ...x});
        } else m.set(x.id, x);
    })
    return [...m.values()].sort((a, b) => a.id - b.id);
};