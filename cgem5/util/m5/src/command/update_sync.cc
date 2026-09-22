#include "args.hh"
#include "command.hh"
#include "dispatch_table.hh"

namespace
{

bool
do_update_sync(const DispatchTable &dt, Args &args)
{
    uint64_t sync_val;

    if (!args.pop(sync_val, 0))
        return false;

    (*dt.m5_update_sync)(sync_val);

    return true;
}

Command update_sync_cmd = {
    "update_sync", 0, 1, do_update_sync, "[value]\n"
        "        Update an integer sync value to the host environment." };

} // anonymous namespace

