#include "plug.h"
#include <stdio.h>
#include <Windows.h>

HMODULE init_plug(plug_function_t *plug_function);
HMODULE init_plug_init(plug_init_t *plug_init);
HMODULE init_plug_update(plug_update_t *plug_update);


int main()
{
    plug_function_t plug_function = NULL;
    plug_init_t plug_init = NULL;
    plug_update_t plug_update = NULL;

    HMODULE libplug = init_plug(&plug_function);
    if (!libplug) {
        FreeLibrary(libplug);
        return 1;
    }

    HMODULE libplug_init = init_plug_init(&plug_init);
    if (!libplug_init) {
        FreeLibrary(libplug_init);
        return 1;
    }

    HMODULE libplug_update = init_plug_update(&plug_update);
    if (!libplug_update) {
        FreeLibrary(libplug_update);
        return 1;
    }

    plug_function();
    plug_init();
    plug_update();

    // Free the library after we're done using it
    FreeLibrary(libplug);
    FreeLibrary(libplug_init);
    FreeLibrary(libplug_update);
    return 0;
}

HMODULE init_plug(plug_function_t *plug_function)
{

    const char *libplug_file_name = "build/plug.dll";
    HMODULE libplug = LoadLibraryA(libplug_file_name);
    if (!libplug)
    {
        printf("Failed to load %s\n", libplug_file_name);
        return NULL;
    }
    *plug_function = (plug_function_t)GetProcAddress(libplug, "plug_function");
    if (!*plug_function)
    {
        printf("Failed to get plug_function address.\n");
        FreeLibrary(libplug);
        return NULL;
    }

    return libplug;
}


HMODULE init_plug_init(plug_init_t *plug_init)
{

    const char *libplug_file_name = "build/plug.dll";
    HMODULE libplug = LoadLibraryA(libplug_file_name);
    if (!libplug)
    {
        printf("Failed to load %s\n", libplug_file_name);
        return NULL;
    }
    *plug_init = (plug_init_t)GetProcAddress(libplug, "plug_init");
    if (!*plug_init)
    {
        printf("Failed to get plug_init address.\n");
        FreeLibrary(libplug);
        return NULL;
    }

    return libplug;
}


HMODULE init_plug_update(plug_update_t *plug_update)
{

    const char *libplug_file_name = "build/plug.dll";
    HMODULE libplug = LoadLibraryA(libplug_file_name);
    if (!libplug)
    {
        printf("Failed to load %s\n", libplug_file_name);
        return NULL;
    }
    *plug_update = (plug_update_t)GetProcAddress(libplug, "plug_update");
    if (!*plug_update)
    {
        printf("Failed to get plug_update address.\n");
        FreeLibrary(libplug);
        return NULL;
    }

    return libplug;
}