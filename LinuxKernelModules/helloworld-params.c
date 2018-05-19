/** helloworld-params.c
 *  Kernel module with dummy parameters
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>

static char *mystr = "hello";
static int myint = 1;
static int myarr[3] = {0, 1, 2};

/* Macro defining module parameters */
module_param(myint, int, S_IRUGO);
module_param(mystr, charp, S_IRUGO);
module_param_array(myarr, int,NULL, S_IWUSR|S_IRUSR);

/* Macro defining module description to be shown in modinfo */
MODULE_PARM_DESC(myint,"this is my int variable");
MODULE_PARM_DESC(mystr,"this is my char pointer variable");
MODULE_PARM_DESC(myarr,"this is my array of int");
MODULE_INFO(my_field_name, "Sample kernel module accepting parameters");

static int __init helloworld_init(void) {
    pr_info("Hello world with parameters!\n");
    pr_info("The *mystr* parameter: %s\n", mystr);
    pr_info("The *myint* parameter: %d\n", myint);
    pr_info("The *myarr* parameter: %d, %d, %d\n", myarr[0], myarr[1], myarr[2]);
    return 0;
}

static void __exit helloworld_exit(void) {
    pr_info("End of the world\n");
}

module_init(helloworld_init);
module_exit(helloworld_exit);
MODULE_AUTHOR("Honey S <honey.sambhu@gmail.com>");
MODULE_LICENSE("GPL");
