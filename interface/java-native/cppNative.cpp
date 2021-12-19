#include "javaNative.h"

#include <memory>
#include <functional>
#include <iostream>

using std::string;
using std::function;
using std::unique_ptr;
using std::shared_ptr;
using std::cout;
using std::endl;


class jstring_deleter
{
    JNIEnv *m_env;
    jstring m_jstr;

public:

    jstring_deleter(JNIEnv *env, jstring jstr)
        : m_env(env)
        , m_jstr(jstr)
    {
    }

    void operator()(const char *cstr)
    {
        cout << "[DEBUG] Releasing " << cstr << endl;
        m_env->ReleaseStringUTFChars(m_jstr, cstr);
    }

};

const string ToString(JNIEnv *env, jstring jstr)
{
    jstring_deleter deleter(env, jstr);     // using a function object
    unique_ptr<const char, jstring_deleter> pcstr(
            env->GetStringUTFChars(jstr, JNI_FALSE),
            deleter );

    return string( pcstr.get() );
}


shared_ptr<const char> ToStringPtr(JNIEnv *env, jstring jstr)
{
    function<void(const char*)> deleter =   // using a lambda
        [env, jstr](const char *cstr) -> void
        {
            cout << "[DEBUG] Releasing " << cstr << endl;
            env->ReleaseStringUTFChars(jstr, cstr);
        };

    return shared_ptr<const char>(
            env->GetStringUTFChars(jstr, JNI_FALSE),
            deleter );
}

void DoSayHello(const string &name)
{
    cout << "Hello, " << name << endl;
}

/*
 * Class:     HelloJNI
 * Method:    sayHello
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_javaNative_sayHello
  (JNIEnv *env, jobject thisObj, jstring arg)
{
    DoSayHello(ToString(env, arg));

    //const string name = ToStringPtr(env, arg).get();
    //DoSayHello(name);
}
