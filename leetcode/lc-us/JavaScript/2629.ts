type F = (x: number) => number;

function compose(functions: F[]): F {
    return (int) => functions.reduceRight((ans, fn) => fn(ans), int);
}