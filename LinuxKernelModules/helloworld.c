/** helloworld.c 
 *  My first kernel module
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

/* Init function of the module */
static int __init helloworld_init(void) {
    pr_info("Hello world!\n");
    return 0;
}

/* Exit function of the module */
static void __exit helloworld_exit(void) {
    pr_info("End of the world\n");
}

module_init(helloworld_init);
module_exit(helloworld_exit);
MODULE_AUTHOR("Honey S <honey.sambhu@gmail.com>");
MODULE_LICENSE("GPL");
