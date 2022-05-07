#ifndef STORAGE_H
#define STORAGE_H

///
/// \brief The Storage class
/// stores and transfer data between modules
///
class Storage
{
public:
    Storage();

    void set_a(float value);
    void set_L0(float value);
    void set_Q(float value);

    float get_a();
    float get_L0();
    float get_Q();

    bool isEmpty_a();
    bool isEmpty_L0();
    bool isEmpty_Q();

    /// myabe add a stack
    /// that holds a few previous calculations
private:
    float a;
    float L0;
    float Q;
};

#endif // STORAGE_H
