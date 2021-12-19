public class javaNative {
    static {
        System.loadLibrary("cppNative");    // loads libhello.so
    }

    private native void sayHello(String name);

    public static void main(String[] args) {
        new javaNative().sayHello("Peace");
    }
}
