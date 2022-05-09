#ifndef STORAGE_H
#define STORAGE_H

///
/// \brief The Storage class
/// stores and transfer data between modules
///
///
struct QStruct{
    float QnpV;
    float Qnpm;
};

class Storage
{
public:
    Storage();

    void set_a(float value);
    void set_L0(float value);
    void set_QnpV(float value);
    void set_Qnpm(float value);

    float get_a();
    float get_L0();
    QStruct get_Q();

    bool isEmpty_a();
    bool isEmpty_L0();
    bool isEmpty_QnpV();
    bool isEmpty_Qnpm();

    /// myabe add a stack
    /// that holds a few previous calculations
private:
    float a;
    float L0;
    QStruct Q;
};

#endif // STORAGE_H
