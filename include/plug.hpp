#ifndef __PLUG_H__
#define __PLUG_H__

extern "C"
{

    __declspec(dllexport) void plug_function(void);
    __declspec(dllexport) void plug_init(void);
    __declspec(dllexport) void plug_update(void);

    typedef void (*plug_function_t)(void);
    typedef void (*plug_init_t)(void);
    typedef void (*plug_update_t)(void);
}

#endif // __PLUG_H__