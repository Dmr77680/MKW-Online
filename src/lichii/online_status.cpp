// SPDX-FileCopyrightText: Copyright 2026 Eden Emulator Project
// SPDX-License-Identifier: GPL-3.0-or-later

// httplib must stay the first include: it pulls in winsock2.h, which clashes with an earlier
// windows.h.
#include "common/httplib.h"

#include <cstdlib>
#include <string>

#include "online_status.h"

int FetchOnlinePlayerCount() {
    try {
        httplib::Client cli("2.29.165.22", 8088);
        cli.set_connection_timeout(3);
        cli.set_read_timeout(3);
        if (auto res = cli.Get("/status"); res && res->status == 200) {
            const std::string& body = res->body;
            const auto key = body.find("\"online\"");
            if (key != std::string::npos) {
                const auto colon = body.find(':', key);
                if (colon != std::string::npos) {
                    return std::atoi(body.c_str() + colon + 1);
                }
            }
        }
    } catch (...) {
    }
    return -1;
}
