// SPDX-FileCopyrightText: Copyright 2026 Eden Emulator Project
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

/// Asks the online server how many players are connected right now.
/// Blocks for a few seconds at most, so call it from a worker thread.
/// Returns -1 when the server cannot be reached.
int FetchOnlinePlayerCount();
