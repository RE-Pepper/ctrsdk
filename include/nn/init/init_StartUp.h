#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*nninitStaticInitFunc) ();

void nninitSystem ();
void nninitSetupDaemons ();
void nninitCallStaticInitializers ();
void nninitSetup ();

#ifdef __cplusplus
}
#endif
