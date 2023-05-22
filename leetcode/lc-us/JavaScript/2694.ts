type Callback = (...args: any[]) => any;
type Subscription = {
    unsubscribe: () => void
}

class EventEmitter {
    #eventsMap: Map<string, Set<Callback>> = new Map();

    subscribe(eventName: string, callback: Callback): Subscription {
        this.#eventsMap.set(eventName, (this.#eventsMap.get(eventName) ?? new Set()).add(callback));
        return {
            unsubscribe: () => {
                this.#eventsMap.get(eventName)?.delete(callback);
            }
        };
    }

    emit(eventName: string, args: any[] = []): any {
        return [...(this.#eventsMap.get(eventName) ?? [])].map(fn => fn?.(...args));
    }
}