#include <stdlib.h>
#include "data.h"

mda_data_t* mda_data_create(void)
{
    mda_data_t *data;

    data = malloc(sizeof(mda_data_t));
    if (!data)
        goto error;

    data->lattice = lattice_create();

    data->last_flow_id = 0;
    
    /* options */
    data->confidence = 95;

    /* internal data */
    data->loop = NULL;
    data->skel = NULL;

    return data;

error:
    return NULL;
}

void mda_data_free(mda_data_t* data)
{
    lattice_free(data->lattice, NULL); /* XXX ELEMENT_FREE */
    free(data);
}
