#include <string>
#include <sstream>
#include <assert.h>

#include "serialise.hh"
#include "archive.hh"

using std::string;
using namespace nix;

int
main(int argc, char **argv)
{
    assert(argc == 3);
    
    string action = argv[1];
    string path = argv[2];

    if (action == "dump") {
        FdSink sink(STDOUT_FILENO);
        dumpPath(path, sink);
    } else if (action == "restore") {
        FdSource source(STDIN_FILENO);
        restorePath(path, source);
    }

    return 0;
}

/* vim: sts=4 sw=4 et */
