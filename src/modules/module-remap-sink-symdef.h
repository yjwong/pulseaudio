#ifndef foomoduleremapsinksymdeffoo
#define foomoduleremapsinksymdeffoo

#include <pulsecore/core.h>
#include <pulsecore/module.h>

#define pa__init module_remap_sink_LTX_pa__init
#define pa__done module_remap_sink_LTX_pa__done
#define pa__get_author module_remap_sink_LTX_pa__get_author
#define pa__get_description module_remap_sink_LTX_pa__get_description
#define pa__get_usage module_remap_sink_LTX_pa__get_usage
#define pa__get_version module_remap_sink_LTX_pa__get_version

int pa__init(pa_module*m);
void pa__done(pa_module*m);

const char* pa__get_author(void);
const char* pa__get_description(void);
const char* pa__get_usage(void);
const char* pa__get_version(void);

#endif