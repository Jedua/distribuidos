/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "uber.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

enum clnt_stat 
solicitar_viaje_1(Posicion *argp, InfoAuto *clnt_res, CLIENT *clnt)
{
	return (clnt_call(clnt, solicitar_viaje,
		(xdrproc_t) xdr_Posicion, (caddr_t) argp,
		(xdrproc_t) xdr_InfoAuto, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
terminar_viaje_1(TerminaViajeArgs *argp, void *clnt_res, CLIENT *clnt)
{
	return (clnt_call(clnt, terminar_viaje,
		(xdrproc_t) xdr_TerminaViajeArgs, (caddr_t) argp,
		(xdrproc_t) xdr_void, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
estado_servicio_1(void *argp, InfoServicio *clnt_res, CLIENT *clnt)
{
	return (clnt_call(clnt, estado_servicio,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_InfoServicio, (caddr_t) clnt_res,
		TIMEOUT));
}
