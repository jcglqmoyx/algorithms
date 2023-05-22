declare global {
    interface Function {
        callPolyfill(context: Record<any, any>, ...args: any[]): any;
    }
}

Function.prototype.callPolyfill = function (this: Function, context: Record<PropertyKey, any>, ...args: any[]): any {
    const sym = Symbol();
    context[sym] = this; //这里的this为调用call的函数本身
    const res = context[sym](...args);
    delete context[sym];
    return res;
}