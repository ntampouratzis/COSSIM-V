#include "args.hh"
#include "command.hh"
#include "dispatch_table.hh"

namespace
{

bool
do_start_sync(const DispatchTable &dt, Args &args)
{
    uint64_t sync_val;

    if (!args.pop(sync_val, 0))
        return false;

    (*dt.m5_start_sync)(sync_val);

    return true;
}

Command start_sync_cmd = {
    "start_sync", 0, 1, do_start_sync, "[value]\n"
        "        Send an integer sync value to the host environment." };

} // anonymous namespace

