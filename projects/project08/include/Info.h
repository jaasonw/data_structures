template <typename T>
struct Info {
    T item;
    int priority;

    Info();
    Info(T i, int p);

    friend std::ostream& operator<<(std::ostream& outs, const Info<T>& info) {
        return outs << info.item << '(' << info.priority << ')';
    }
    friend bool operator<(const Info<T>& left, const Info<T>& right) {
        return left.priority < right.priority;
    }
    friend bool operator>(const Info<T>& left, const Info<T>& right) {
        return left.priority > right.priority;
    }
    T operator*() { return item; }
};

template <typename T>
Info<T>::Info() {
    item = T();
    priority = 0;
}
template <typename T>
Info<T>::Info(T i, int p) {
    item = i;
    priority = p;
}