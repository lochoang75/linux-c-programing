#include <stdlib.h>
#include "tlpi_hdr.h"
#include "log.h"

extern char **environ;
static int _setenv(const char *name, const char *value, int overwrite);
static int _unsetenv(const char *name);

static void _print_all_env()
{
    char **ep;
    for (ep = environ; *ep != NULL; ep++)
    {
        log_debug(*ep);
    }
}

int main(int argc, char* argv[])
{
    log_debug("Environment before set/get");
    _print_all_env();

    const char *name = "foo";
    const char *value = "bar";
    log_debug("Set env with name %s and value %d", name, value);
    setenv(name, value, 0);
    log_debug("Print after set");
    _print_all_env();

    log_debug("Clear env");
    unsetenv(name);
    log_debug("Print after clear");
    _print_all_env();

    log_debug("Set env with name %s and value %d", name, value);
    _setenv(name, value, 0);
    _setenv(name, "clue", 0);
    log_debug("Print after set");
    _print_all_env();

    log_debug("Clear env");
    _unsetenv(name);
    log_debug("Print after clear");
    _print_all_env();
    return 0;
}

static int _setenv(const char *name, const char *value, int overwrite)
{
    char *buffer = (char*)malloc(strlen(name) + strlen(value) + 2);
    sprintf(buffer, "%s=%s", name, value);
    putenv(buffer);
    return 0;
}

static int _unsetenv(const char *name)
{
    putenv((char*)name);
}