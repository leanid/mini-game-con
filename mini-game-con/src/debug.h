#ifndef DEBUG_H_
#define DEBUG_H_

#ifdef __cplusplus
extern "C"
{
#endif

extern void debug_init(void);
extern void debug_set_hook_on_crush(int signal);

#ifdef __cplusplus
} // end extern "C"
#endif
#endif /* DEBUG_H_ */
