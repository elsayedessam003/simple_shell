{"payload":{"allShortcutsEnabled":false,"fileTree":{"":{"items":[{"name":".gitignore","path":".gitignore","contentType":"file"},{"name":"AUTHORS","path":"AUTHORS","contentType":"file"},{"name":"README.md","path":"README.md","contentType":"file"},{"name":"aux_error1.c","path":"aux_error1.c","contentType":"file"},{"name":"aux_error2.c","path":"aux_error2.c","contentType":"file"},{"name":"aux_help.c","path":"aux_help.c","contentType":"file"},{"name":"aux_help2.c","path":"aux_help2.c","contentType":"file"},{"name":"aux_lists.c","path":"aux_lists.c","contentType":"file"},{"name":"aux_lists2.c","path":"aux_lists2.c","contentType":"file"},{"name":"aux_mem.c","path":"aux_mem.c","contentType":"file"},{"name":"aux_stdlib.c","path":"aux_stdlib.c","contentType":"file"},{"name":"aux_str.c","path":"aux_str.c","contentType":"file"},{"name":"aux_str2.c","path":"aux_str2.c","contentType":"file"},{"name":"aux_str3.c","path":"aux_str3.c","contentType":"file"},{"name":"cd.c","path":"cd.c","contentType":"file"},{"name":"cd_shell.c","path":"cd_shell.c","contentType":"file"},{"name":"check_syntax_error.c","path":"check_syntax_error.c","contentType":"file"},{"name":"cmd_exec.c","path":"cmd_exec.c","contentType":"file"},{"name":"env1.c","path":"env1.c","contentType":"file"},{"name":"env2.c","path":"env2.c","contentType":"file"},{"name":"exec_line.c","path":"exec_line.c","contentType":"file"},{"name":"exit_shell.c","path":"exit_shell.c","contentType":"file"},{"name":"get_builtin.c","path":"get_builtin.c","contentType":"file"},{"name":"get_error.c","path":"get_error.c","contentType":"file"},{"name":"get_help.c","path":"get_help.c","contentType":"file"},{"name":"get_line.c","path":"get_line.c","contentType":"file"},{"name":"get_sigint.c","path":"get_sigint.c","contentType":"file"},{"name":"holberton.h","path":"holberton.h","contentType":"file"},{"name":"main.c","path":"main.c","contentType":"file"},{"name":"man_1_simple_shell","path":"man_1_simple_shell","contentType":"file"},{"name":"read_line.c","path":"read_line.c","contentType":"file"},{"name":"rep_var.c","path":"rep_var.c","contentType":"file"},{"name":"shell_loop.c","path":"shell_loop.c","contentType":"file"},{"name":"split.c","path":"split.c","contentType":"file"}],"totalCount":34}},"fileTreeProcessingTime":5.183653,"foldersToFetch":[],"reducedMotionEnabled":null,"repo":{"id":202782214,"defaultBranch":"master","name":"simple_shell","ownerLogin":"luischaparroc","currentUserCanPush":false,"isFork":false,"isEmpty":false,"createdAt":"2019-08-16T18:48:05.000Z","ownerAvatar":"https://avatars.githubusercontent.com/u/43935218?v=4","public":true,"private":false,"isOrgOwned":false},"symbolsExpanded":false,"treeExpanded":true,"refInfo":{"name":"082057d3703bdc5800c838c14fb07b3d4b2f3c03","listCacheKey":"v0:1565983020.0","canEdit":false,"refType":"tree","currentOid":"082057d3703bdc5800c838c14fb07b3d4b2f3c03"},"path":"rep_var.c","currentUser":null,"blob":{"rawLines":["#include \"holberton.h\"","","/**"," * check_env - checks if the typed variable is an env variable"," *"," * @h: head of linked list"," * @in: input string"," * @data: data structure"," * Return: no return"," */","void check_env(r_var **h, char *in, data_shell *data)","{","\tint row, chr, j, lval;","\tchar **_envr;","","\t_envr = data->_environ;","\tfor (row = 0; _envr[row]; row++)","\t{","\t\tfor (j = 1, chr = 0; _envr[row][chr]; chr++)","\t\t{","\t\t\tif (_envr[row][chr] == '=')","\t\t\t{","\t\t\t\tlval = _strlen(_envr[row] + chr + 1);","\t\t\t\tadd_rvar_node(h, j, _envr[row] + chr + 1, lval);","\t\t\t\treturn;","\t\t\t}","","\t\t\tif (in[j] == _envr[row][chr])","\t\t\t\tj++;","\t\t\telse","\t\t\t\tbreak;","\t\t}","\t}","","\tfor (j = 0; in[j]; j++)","\t{","\t\tif (in[j] == ' ' || in[j] == '\\t' || in[j] == ';' || in[j] == '\\n')","\t\t\tbreak;","\t}","","\tadd_rvar_node(h, j, NULL, 0);","}","","/**"," * check_vars - check if the typed variable is $$ or $?"," *"," * @h: head of the linked list"," * @in: input string"," * @st: last status of the Shell"," * @data: data structure"," * Return: no return"," */","int check_vars(r_var **h, char *in, char *st, data_shell *data)","{","\tint i, lst, lpd;","","\tlst = _strlen(st);","\tlpd = _strlen(data->pid);","","\tfor (i = 0; in[i]; i++)","\t{","\t\tif (in[i] == '$')","\t\t{","\t\t\tif (in[i + 1] == '?')","\t\t\t\tadd_rvar_node(h, 2, st, lst), i++;","\t\t\telse if (in[i + 1] == '$')","\t\t\t\tadd_rvar_node(h, 2, data->pid, lpd), i++;","\t\t\telse if (in[i + 1] == '\\n')","\t\t\t\tadd_rvar_node(h, 0, NULL, 0);","\t\t\telse if (in[i + 1] == '\\0')","\t\t\t\tadd_rvar_node(h, 0, NULL, 0);","\t\t\telse if (in[i + 1] == ' ')","\t\t\t\tadd_rvar_node(h, 0, NULL, 0);","\t\t\telse if (in[i + 1] == '\\t')","\t\t\t\tadd_rvar_node(h, 0, NULL, 0);","\t\t\telse if (in[i + 1] == ';')","\t\t\t\tadd_rvar_node(h, 0, NULL, 0);","\t\t\telse","\t\t\t\tcheck_env(h, in + i, data);","\t\t}","\t}","","\treturn (i);","}","","/**"," * replaced_input - replaces string into variables"," *"," * @head: head of the linked list"," * @input: input string"," * @new_input: new input string (replaced)"," * @nlen: new length"," * Return: replaced string"," */","char *replaced_input(r_var **head, char *input, char *new_input, int nlen)","{","\tr_var *indx;","\tint i, j, k;","","\tindx = *head;","\tfor (j = i = 0; i < nlen; i++)","\t{","\t\tif (input[j] == '$')","\t\t{","\t\t\tif (!(indx->len_var) && !(indx->len_val))","\t\t\t{","\t\t\t\tnew_input[i] = input[j];","\t\t\t\tj++;","\t\t\t}","\t\t\telse if (indx->len_var && !(indx->len_val))","\t\t\t{","\t\t\t\tfor (k = 0; k < indx->len_var; k++)","\t\t\t\t\tj++;","\t\t\t\ti--;","\t\t\t}","\t\t\telse","\t\t\t{","\t\t\t\tfor (k = 0; k < indx->len_val; k++)","\t\t\t\t{","\t\t\t\t\tnew_input[i] = indx->val[k];","\t\t\t\t\ti++;","\t\t\t\t}","\t\t\t\tj += (indx->len_var);","\t\t\t\ti--;","\t\t\t}","\t\t\tindx = indx->next;","\t\t}","\t\telse","\t\t{","\t\t\tnew_input[i] = input[j];","\t\t\tj++;","\t\t}","\t}","","\treturn (new_input);","}","","/**"," * rep_var - calls functions to replace string into vars"," *"," * @input: input string"," * @datash: data structure"," * Return: replaced string"," */","char *rep_var(char *input, data_shell *datash)","{","\tr_var *head, *indx;","\tchar *status, *new_input;","\tint olen, nlen;","","\tstatus = aux_itoa(datash->status);","\thead = NULL;","","\tolen = check_vars(&head, input, status, datash);","","\tif (head == NULL)","\t{","\t\tfree(status);","\t\treturn (input);","\t}","","\tindx = head;","\tnlen = 0;","","\twhile (indx != NULL)","\t{","\t\tnlen += (indx->len_val - indx->len_var);","\t\tindx = indx->next;","\t}","","\tnlen += olen;","","\tnew_input = malloc(sizeof(char) * (nlen + 1));","\tnew_input[nlen] = '\\0';","","\tnew_input = replaced_input(&head, input, new_input, nlen);","","\tfree(input);","\tfree(status);","\tfree_rvar_list(&head);","","\treturn (new_input);","}"],"stylingDirectives":[[{"start":0,"end":8,"cssClass":"pl-k"},{"start":9,"end":22,"cssClass":"pl-s"}],[],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":62,"cssClass":"pl-c"}],[{"start":0,"end":2,"cssClass":"pl-c"}],[{"start":0,"end":26,"cssClass":"pl-c"}],[{"start":0,"end":20,"cssClass":"pl-c"}],[{"start":0,"end":24,"cssClass":"pl-c"}],[{"start":0,"end":20,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":4,"cssClass":"pl-smi"},{"start":5,"end":14,"cssClass":"pl-en"},{"start":15,"end":20,"cssClass":"pl-smi"},{"start":21,"end":22,"cssClass":"pl-c1"},{"start":22,"end":23,"cssClass":"pl-c1"},{"start":23,"end":24,"cssClass":"pl-s1"},{"start":26,"end":30,"cssClass":"pl-smi"},{"start":31,"end":32,"cssClass":"pl-c1"},{"start":32,"end":34,"cssClass":"pl-s1"},{"start":36,"end":46,"cssClass":"pl-smi"},{"start":47,"end":48,"cssClass":"pl-c1"},{"start":48,"end":52,"cssClass":"pl-s1"}],[],[{"start":1,"end":4,"cssClass":"pl-smi"},{"start":5,"end":8,"cssClass":"pl-s1"},{"start":10,"end":13,"cssClass":"pl-s1"},{"start":15,"end":16,"cssClass":"pl-s1"},{"start":18,"end":22,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-smi"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":7,"end":8,"cssClass":"pl-c1"},{"start":8,"end":13,"cssClass":"pl-s1"}],[],[{"start":1,"end":6,"cssClass":"pl-s1"},{"start":7,"end":8,"cssClass":"pl-c1"},{"start":9,"end":13,"cssClass":"pl-s1"},{"start":13,"end":15,"cssClass":"pl-c1"},{"start":15,"end":23,"cssClass":"pl-c1"}],[{"start":1,"end":4,"cssClass":"pl-k"},{"start":6,"end":9,"cssClass":"pl-s1"},{"start":10,"end":11,"cssClass":"pl-c1"},{"start":12,"end":13,"cssClass":"pl-c1"},{"start":15,"end":20,"cssClass":"pl-s1"},{"start":21,"end":24,"cssClass":"pl-s1"},{"start":27,"end":30,"cssClass":"pl-s1"},{"start":30,"end":32,"cssClass":"pl-c1"}],[],[{"start":2,"end":5,"cssClass":"pl-k"},{"start":7,"end":8,"cssClass":"pl-s1"},{"start":9,"end":10,"cssClass":"pl-c1"},{"start":11,"end":12,"cssClass":"pl-c1"},{"start":14,"end":17,"cssClass":"pl-s1"},{"start":18,"end":19,"cssClass":"pl-c1"},{"start":20,"end":21,"cssClass":"pl-c1"},{"start":23,"end":28,"cssClass":"pl-s1"},{"start":29,"end":32,"cssClass":"pl-s1"},{"start":34,"end":37,"cssClass":"pl-s1"},{"start":40,"end":43,"cssClass":"pl-s1"},{"start":43,"end":45,"cssClass":"pl-c1"}],[],[{"start":3,"end":5,"cssClass":"pl-k"},{"start":7,"end":12,"cssClass":"pl-s1"},{"start":13,"end":16,"cssClass":"pl-s1"},{"start":18,"end":21,"cssClass":"pl-s1"},{"start":23,"end":25,"cssClass":"pl-c1"},{"start":26,"end":29,"cssClass":"pl-c1"}],[],[{"start":4,"end":8,"cssClass":"pl-s1"},{"start":9,"end":10,"cssClass":"pl-c1"},{"start":11,"end":18,"cssClass":"pl-en"},{"start":19,"end":24,"cssClass":"pl-s1"},{"start":25,"end":28,"cssClass":"pl-s1"},{"start":30,"end":31,"cssClass":"pl-c1"},{"start":32,"end":35,"cssClass":"pl-s1"},{"start":36,"end":37,"cssClass":"pl-c1"},{"start":38,"end":39,"cssClass":"pl-c1"}],[{"start":4,"end":17,"cssClass":"pl-en"},{"start":18,"end":19,"cssClass":"pl-s1"},{"start":21,"end":22,"cssClass":"pl-s1"},{"start":24,"end":29,"cssClass":"pl-s1"},{"start":30,"end":33,"cssClass":"pl-s1"},{"start":35,"end":36,"cssClass":"pl-c1"},{"start":37,"end":40,"cssClass":"pl-s1"},{"start":41,"end":42,"cssClass":"pl-c1"},{"start":43,"end":44,"cssClass":"pl-c1"},{"start":46,"end":50,"cssClass":"pl-s1"}],[{"start":4,"end":10,"cssClass":"pl-k"}],[],[],[{"start":3,"end":5,"cssClass":"pl-k"},{"start":7,"end":9,"cssClass":"pl-s1"},{"start":10,"end":11,"cssClass":"pl-s1"},{"start":13,"end":15,"cssClass":"pl-c1"},{"start":16,"end":21,"cssClass":"pl-s1"},{"start":22,"end":25,"cssClass":"pl-s1"},{"start":27,"end":30,"cssClass":"pl-s1"}],[{"start":4,"end":5,"cssClass":"pl-s1"},{"start":5,"end":7,"cssClass":"pl-c1"}],[{"start":3,"end":7,"cssClass":"pl-k"}],[{"start":4,"end":9,"cssClass":"pl-k"}],[],[],[],[{"start":1,"end":4,"cssClass":"pl-k"},{"start":6,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":11,"cssClass":"pl-c1"},{"start":13,"end":15,"cssClass":"pl-s1"},{"start":16,"end":17,"cssClass":"pl-s1"},{"start":20,"end":21,"cssClass":"pl-s1"},{"start":21,"end":23,"cssClass":"pl-c1"}],[],[{"start":2,"end":4,"cssClass":"pl-k"},{"start":6,"end":8,"cssClass":"pl-s1"},{"start":9,"end":10,"cssClass":"pl-s1"},{"start":12,"end":14,"cssClass":"pl-c1"},{"start":15,"end":18,"cssClass":"pl-c1"},{"start":19,"end":21,"cssClass":"pl-c1"},{"start":22,"end":24,"cssClass":"pl-s1"},{"start":25,"end":26,"cssClass":"pl-s1"},{"start":28,"end":30,"cssClass":"pl-c1"},{"start":31,"end":35,"cssClass":"pl-c1"},{"start":36,"end":38,"cssClass":"pl-c1"},{"start":39,"end":41,"cssClass":"pl-s1"},{"start":42,"end":43,"cssClass":"pl-s1"},{"start":45,"end":47,"cssClass":"pl-c1"},{"start":48,"end":51,"cssClass":"pl-c1"},{"start":52,"end":54,"cssClass":"pl-c1"},{"start":55,"end":57,"cssClass":"pl-s1"},{"start":58,"end":59,"cssClass":"pl-s1"},{"start":61,"end":63,"cssClass":"pl-c1"},{"start":64,"end":68,"cssClass":"pl-c1"}],[{"start":3,"end":8,"cssClass":"pl-k"}],[],[],[{"start":1,"end":14,"cssClass":"pl-en"},{"start":15,"end":16,"cssClass":"pl-s1"},{"start":18,"end":19,"cssClass":"pl-s1"},{"start":21,"end":25,"cssClass":"pl-c1"},{"start":27,"end":28,"cssClass":"pl-c1"}],[],[],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":55,"cssClass":"pl-c"}],[{"start":0,"end":2,"cssClass":"pl-c"}],[{"start":0,"end":30,"cssClass":"pl-c"}],[{"start":0,"end":20,"cssClass":"pl-c"}],[{"start":0,"end":32,"cssClass":"pl-c"}],[{"start":0,"end":24,"cssClass":"pl-c"}],[{"start":0,"end":20,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-smi"},{"start":4,"end":14,"cssClass":"pl-en"},{"start":15,"end":20,"cssClass":"pl-smi"},{"start":21,"end":22,"cssClass":"pl-c1"},{"start":22,"end":23,"cssClass":"pl-c1"},{"start":23,"end":24,"cssClass":"pl-s1"},{"start":26,"end":30,"cssClass":"pl-smi"},{"start":31,"end":32,"cssClass":"pl-c1"},{"start":32,"end":34,"cssClass":"pl-s1"},{"start":36,"end":40,"cssClass":"pl-smi"},{"start":41,"end":42,"cssClass":"pl-c1"},{"start":42,"end":44,"cssClass":"pl-s1"},{"start":46,"end":56,"cssClass":"pl-smi"},{"start":57,"end":58,"cssClass":"pl-c1"},{"start":58,"end":62,"cssClass":"pl-s1"}],[],[{"start":1,"end":4,"cssClass":"pl-smi"},{"start":5,"end":6,"cssClass":"pl-s1"},{"start":8,"end":11,"cssClass":"pl-s1"},{"start":13,"end":16,"cssClass":"pl-s1"}],[],[{"start":1,"end":4,"cssClass":"pl-s1"},{"start":5,"end":6,"cssClass":"pl-c1"},{"start":7,"end":14,"cssClass":"pl-en"},{"start":15,"end":17,"cssClass":"pl-s1"}],[{"start":1,"end":4,"cssClass":"pl-s1"},{"start":5,"end":6,"cssClass":"pl-c1"},{"start":7,"end":14,"cssClass":"pl-en"},{"start":15,"end":19,"cssClass":"pl-s1"},{"start":19,"end":21,"cssClass":"pl-c1"},{"start":21,"end":24,"cssClass":"pl-c1"}],[],[{"start":1,"end":4,"cssClass":"pl-k"},{"start":6,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":11,"cssClass":"pl-c1"},{"start":13,"end":15,"cssClass":"pl-s1"},{"start":16,"end":17,"cssClass":"pl-s1"},{"start":20,"end":21,"cssClass":"pl-s1"},{"start":21,"end":23,"cssClass":"pl-c1"}],[],[{"start":2,"end":4,"cssClass":"pl-k"},{"start":6,"end":8,"cssClass":"pl-s1"},{"start":9,"end":10,"cssClass":"pl-s1"},{"start":12,"end":14,"cssClass":"pl-c1"},{"start":15,"end":18,"cssClass":"pl-c1"}],[],[{"start":3,"end":5,"cssClass":"pl-k"},{"start":7,"end":9,"cssClass":"pl-s1"},{"start":10,"end":11,"cssClass":"pl-s1"},{"start":12,"end":13,"cssClass":"pl-c1"},{"start":14,"end":15,"cssClass":"pl-c1"},{"start":17,"end":19,"cssClass":"pl-c1"},{"start":20,"end":23,"cssClass":"pl-c1"}],[{"start":4,"end":17,"cssClass":"pl-en"},{"start":18,"end":19,"cssClass":"pl-s1"},{"start":21,"end":22,"cssClass":"pl-c1"},{"start":24,"end":26,"cssClass":"pl-s1"},{"start":28,"end":31,"cssClass":"pl-s1"},{"start":34,"end":35,"cssClass":"pl-s1"},{"start":35,"end":37,"cssClass":"pl-c1"}],[{"start":3,"end":7,"cssClass":"pl-k"},{"start":8,"end":10,"cssClass":"pl-k"},{"start":12,"end":14,"cssClass":"pl-s1"},{"start":15,"end":16,"cssClass":"pl-s1"},{"start":17,"end":18,"cssClass":"pl-c1"},{"start":19,"end":20,"cssClass":"pl-c1"},{"start":22,"end":24,"cssClass":"pl-c1"},{"start":25,"end":28,"cssClass":"pl-c1"}],[{"start":4,"end":17,"cssClass":"pl-en"},{"start":18,"end":19,"cssClass":"pl-s1"},{"start":21,"end":22,"cssClass":"pl-c1"},{"start":24,"end":28,"cssClass":"pl-s1"},{"start":28,"end":30,"cssClass":"pl-c1"},{"start":30,"end":33,"cssClass":"pl-c1"},{"start":35,"end":38,"cssClass":"pl-s1"},{"start":41,"end":42,"cssClass":"pl-s1"},{"start":42,"end":44,"cssClass":"pl-c1"}],[{"start":3,"end":7,"cssClass":"pl-k"},{"start":8,"end":10,"cssClass":"pl-k"},{"start":12,"end":14,"cssClass":"pl-s1"},{"start":15,"end":16,"cssClass":"pl-s1"},{"start":17,"end":18,"cssClass":"pl-c1"},{"start":19,"end":20,"cssClass":"pl-c1"},{"start":22,"end":24,"cssClass":"pl-c1"},{"start":25,"end":29,"cssClass":"pl-c1"}],[{"start":4,"end":17,"cssClass":"pl-en"},{"start":18,"end":19,"cssClass":"pl-s1"},{"start":21,"end":22,"cssClass":"pl-c1"},{"start":24,"end":28,"cssClass":"pl-c1"},{"start":30,"end":31,"cssClass":"pl-c1"}],[{"start":3,"end":7,"cssClass":"pl-k"},{"start":8,"end":10,"cssClass":"pl-k"},{"start":12,"end":14,"cssClass":"pl-s1"},{"start":15,"end":16,"cssClass":"pl-s1"},{"start":17,"end":18,"cssClass":"pl-c1"},{"start":19,"end":20,"cssClass":"pl-c1"},{"start":22,"end":24,"cssClass":"pl-c1"},{"start":25,"end":29,"cssClass":"pl-c1"}],[{"start":4,"end":17,"cssClass":"pl-en"},{"start":18,"end":19,"cssClass":"pl-s1"},{"start":21,"end":22,"cssClass":"pl-c1"},{"start":24,"end":28,"cssClass":"pl-c1"},{"start":30,"end":31,"cssClass":"pl-c1"}],[{"start":3,"end":7,"cssClass":"pl-k"},{"start":8,"end":10,"cssClass":"pl-k"},{"start":12,"end":14,"cssClass":"pl-s1"},{"start":15,"end":16,"cssClass":"pl-s1"},{"start":17,"end":18,"cssClass":"pl-c1"},{"start":19,"end":20,"cssClass":"pl-c1"},{"start":22,"end":24,"cssClass":"pl-c1"},{"start":25,"end":28,"cssClass":"pl-c1"}],[{"start":4,"end":17,"cssClass":"pl-en"},{"start":18,"end":19,"cssClass":"pl-s1"},{"start":21,"end":22,"cssClass":"pl-c1"},{"start":24,"end":28,"cssClass":"pl-c1"},{"start":30,"end":31,"cssClass":"pl-c1"}],[{"start":3,"end":7,"cssClass":"pl-k"},{"start":8,"end":10,"cssClass":"pl-k"},{"start":12,"end":14,"cssClass":"pl-s1"},{"start":15,"end":16,"cssClass":"pl-s1"},{"start":17,"end":18,"cssClass":"pl-c1"},{"start":19,"end":20,"cssClass":"pl-c1"},{"start":22,"end":24,"cssClass":"pl-c1"},{"start":25,"end":29,"cssClass":"pl-c1"}],[{"start":4,"end":17,"cssClass":"pl-en"},{"start":18,"end":19,"cssClass":"pl-s1"},{"start":21,"end":22,"cssClass":"pl-c1"},{"start":24,"end":28,"cssClass":"pl-c1"},{"start":30,"end":31,"cssClass":"pl-c1"}],[{"start":3,"end":7,"cssClass":"pl-k"},{"start":8,"end":10,"cssClass":"pl-k"},{"start":12,"end":14,"cssClass":"pl-s1"},{"start":15,"end":16,"cssClass":"pl-s1"},{"start":17,"end":18,"cssClass":"pl-c1"},{"start":19,"end":20,"cssClass":"pl-c1"},{"start":22,"end":24,"cssClass":"pl-c1"},{"start":25,"end":28,"cssClass":"pl-c1"}],[{"start":4,"end":17,"cssClass":"pl-en"},{"start":18,"end":19,"cssClass":"pl-s1"},{"start":21,"end":22,"cssClass":"pl-c1"},{"start":24,"end":28,"cssClass":"pl-c1"},{"start":30,"end":31,"cssClass":"pl-c1"}],[{"start":3,"end":7,"cssClass":"pl-k"}],[{"start":4,"end":13,"cssClass":"pl-en"},{"start":14,"end":15,"cssClass":"pl-s1"},{"start":17,"end":19,"cssClass":"pl-s1"},{"start":20,"end":21,"cssClass":"pl-c1"},{"start":22,"end":23,"cssClass":"pl-s1"},{"start":25,"end":29,"cssClass":"pl-s1"}],[],[],[],[{"start":1,"end":7,"cssClass":"pl-k"},{"start":9,"end":10,"cssClass":"pl-s1"}],[],[],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":50,"cssClass":"pl-c"}],[{"start":0,"end":2,"cssClass":"pl-c"}],[{"start":0,"end":33,"cssClass":"pl-c"}],[{"start":0,"end":23,"cssClass":"pl-c"}],[{"start":0,"end":42,"cssClass":"pl-c"}],[{"start":0,"end":20,"cssClass":"pl-c"}],[{"start":0,"end":26,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":4,"cssClass":"pl-smi"},{"start":5,"end":6,"cssClass":"pl-c1"},{"start":6,"end":20,"cssClass":"pl-en"},{"start":21,"end":26,"cssClass":"pl-smi"},{"start":27,"end":28,"cssClass":"pl-c1"},{"start":28,"end":29,"cssClass":"pl-c1"},{"start":29,"end":33,"cssClass":"pl-s1"},{"start":35,"end":39,"cssClass":"pl-smi"},{"start":40,"end":41,"cssClass":"pl-c1"},{"start":41,"end":46,"cssClass":"pl-s1"},{"start":48,"end":52,"cssClass":"pl-smi"},{"start":53,"end":54,"cssClass":"pl-c1"},{"start":54,"end":63,"cssClass":"pl-s1"},{"start":65,"end":68,"cssClass":"pl-smi"},{"start":69,"end":73,"cssClass":"pl-s1"}],[],[{"start":1,"end":6,"cssClass":"pl-smi"},{"start":7,"end":8,"cssClass":"pl-c1"},{"start":8,"end":12,"cssClass":"pl-s1"}],[{"start":1,"end":4,"cssClass":"pl-smi"},{"start":5,"end":6,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-s1"},{"start":11,"end":12,"cssClass":"pl-s1"}],[],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":9,"end":13,"cssClass":"pl-s1"}],[{"start":1,"end":4,"cssClass":"pl-k"},{"start":6,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":11,"cssClass":"pl-s1"},{"start":12,"end":13,"cssClass":"pl-c1"},{"start":14,"end":15,"cssClass":"pl-c1"},{"start":17,"end":18,"cssClass":"pl-s1"},{"start":19,"end":20,"cssClass":"pl-c1"},{"start":21,"end":25,"cssClass":"pl-s1"},{"start":27,"end":28,"cssClass":"pl-s1"},{"start":28,"end":30,"cssClass":"pl-c1"}],[],[{"start":2,"end":4,"cssClass":"pl-k"},{"start":6,"end":11,"cssClass":"pl-s1"},{"start":12,"end":13,"cssClass":"pl-s1"},{"start":15,"end":17,"cssClass":"pl-c1"},{"start":18,"end":21,"cssClass":"pl-c1"}],[],[{"start":3,"end":5,"cssClass":"pl-k"},{"start":9,"end":13,"cssClass":"pl-s1"},{"start":13,"end":15,"cssClass":"pl-c1"},{"start":15,"end":22,"cssClass":"pl-c1"},{"start":24,"end":26,"cssClass":"pl-c1"},{"start":29,"end":33,"cssClass":"pl-s1"},{"start":33,"end":35,"cssClass":"pl-c1"},{"start":35,"end":42,"cssClass":"pl-c1"}],[],[{"start":4,"end":13,"cssClass":"pl-s1"},{"start":14,"end":15,"cssClass":"pl-s1"},{"start":17,"end":18,"cssClass":"pl-c1"},{"start":19,"end":24,"cssClass":"pl-s1"},{"start":25,"end":26,"cssClass":"pl-s1"}],[{"start":4,"end":5,"cssClass":"pl-s1"},{"start":5,"end":7,"cssClass":"pl-c1"}],[],[{"start":3,"end":7,"cssClass":"pl-k"},{"start":8,"end":10,"cssClass":"pl-k"},{"start":12,"end":16,"cssClass":"pl-s1"},{"start":16,"end":18,"cssClass":"pl-c1"},{"start":18,"end":25,"cssClass":"pl-c1"},{"start":26,"end":28,"cssClass":"pl-c1"},{"start":31,"end":35,"cssClass":"pl-s1"},{"start":35,"end":37,"cssClass":"pl-c1"},{"start":37,"end":44,"cssClass":"pl-c1"}],[],[{"start":4,"end":7,"cssClass":"pl-k"},{"start":9,"end":10,"cssClass":"pl-s1"},{"start":11,"end":12,"cssClass":"pl-c1"},{"start":13,"end":14,"cssClass":"pl-c1"},{"start":16,"end":17,"cssClass":"pl-s1"},{"start":18,"end":19,"cssClass":"pl-c1"},{"start":20,"end":24,"cssClass":"pl-s1"},{"start":24,"end":26,"cssClass":"pl-c1"},{"start":26,"end":33,"cssClass":"pl-c1"},{"start":35,"end":36,"cssClass":"pl-s1"},{"start":36,"end":38,"cssClass":"pl-c1"}],[{"start":5,"end":6,"cssClass":"pl-s1"},{"start":6,"end":8,"cssClass":"pl-c1"}],[{"start":4,"end":5,"cssClass":"pl-s1"},{"start":5,"end":7,"cssClass":"pl-c1"}],[],[{"start":3,"end":7,"cssClass":"pl-k"}],[],[{"start":4,"end":7,"cssClass":"pl-k"},{"start":9,"end":10,"cssClass":"pl-s1"},{"start":11,"end":12,"cssClass":"pl-c1"},{"start":13,"end":14,"cssClass":"pl-c1"},{"start":16,"end":17,"cssClass":"pl-s1"},{"start":18,"end":19,"cssClass":"pl-c1"},{"start":20,"end":24,"cssClass":"pl-s1"},{"start":24,"end":26,"cssClass":"pl-c1"},{"start":26,"end":33,"cssClass":"pl-c1"},{"start":35,"end":36,"cssClass":"pl-s1"},{"start":36,"end":38,"cssClass":"pl-c1"}],[],[{"start":5,"end":14,"cssClass":"pl-s1"},{"start":15,"end":16,"cssClass":"pl-s1"},{"start":18,"end":19,"cssClass":"pl-c1"},{"start":20,"end":24,"cssClass":"pl-s1"},{"start":24,"end":26,"cssClass":"pl-c1"},{"start":26,"end":29,"cssClass":"pl-c1"},{"start":30,"end":31,"cssClass":"pl-s1"}],[{"start":5,"end":6,"cssClass":"pl-s1"},{"start":6,"end":8,"cssClass":"pl-c1"}],[],[{"start":4,"end":5,"cssClass":"pl-s1"},{"start":6,"end":8,"cssClass":"pl-c1"},{"start":10,"end":14,"cssClass":"pl-s1"},{"start":14,"end":16,"cssClass":"pl-c1"},{"start":16,"end":23,"cssClass":"pl-c1"}],[{"start":4,"end":5,"cssClass":"pl-s1"},{"start":5,"end":7,"cssClass":"pl-c1"}],[],[{"start":3,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":14,"cssClass":"pl-s1"},{"start":14,"end":16,"cssClass":"pl-c1"},{"start":16,"end":20,"cssClass":"pl-c1"}],[],[{"start":2,"end":6,"cssClass":"pl-k"}],[],[{"start":3,"end":12,"cssClass":"pl-s1"},{"start":13,"end":14,"cssClass":"pl-s1"},{"start":16,"end":17,"cssClass":"pl-c1"},{"start":18,"end":23,"cssClass":"pl-s1"},{"start":24,"end":25,"cssClass":"pl-s1"}],[{"start":3,"end":4,"cssClass":"pl-s1"},{"start":4,"end":6,"cssClass":"pl-c1"}],[],[],[],[{"start":1,"end":7,"cssClass":"pl-k"},{"start":9,"end":18,"cssClass":"pl-s1"}],[],[],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":56,"cssClass":"pl-c"}],[{"start":0,"end":2,"cssClass":"pl-c"}],[{"start":0,"end":23,"cssClass":"pl-c"}],[{"start":0,"end":26,"cssClass":"pl-c"}],[{"start":0,"end":26,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":4,"cssClass":"pl-smi"},{"start":5,"end":6,"cssClass":"pl-c1"},{"start":6,"end":13,"cssClass":"pl-en"},{"start":14,"end":18,"cssClass":"pl-smi"},{"start":19,"end":20,"cssClass":"pl-c1"},{"start":20,"end":25,"cssClass":"pl-s1"},{"start":27,"end":37,"cssClass":"pl-smi"},{"start":38,"end":39,"cssClass":"pl-c1"},{"start":39,"end":45,"cssClass":"pl-s1"}],[],[{"start":1,"end":6,"cssClass":"pl-smi"},{"start":7,"end":8,"cssClass":"pl-c1"},{"start":8,"end":12,"cssClass":"pl-s1"},{"start":14,"end":15,"cssClass":"pl-c1"},{"start":15,"end":19,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-smi"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":7,"end":13,"cssClass":"pl-s1"},{"start":15,"end":16,"cssClass":"pl-c1"},{"start":16,"end":25,"cssClass":"pl-s1"}],[{"start":1,"end":4,"cssClass":"pl-smi"},{"start":5,"end":9,"cssClass":"pl-s1"},{"start":11,"end":15,"cssClass":"pl-s1"}],[],[{"start":1,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":18,"cssClass":"pl-en"},{"start":19,"end":25,"cssClass":"pl-s1"},{"start":25,"end":27,"cssClass":"pl-c1"},{"start":27,"end":33,"cssClass":"pl-c1"}],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":12,"cssClass":"pl-c1"}],[],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":18,"cssClass":"pl-en"},{"start":19,"end":20,"cssClass":"pl-c1"},{"start":20,"end":24,"cssClass":"pl-s1"},{"start":26,"end":31,"cssClass":"pl-s1"},{"start":33,"end":39,"cssClass":"pl-s1"},{"start":41,"end":47,"cssClass":"pl-s1"}],[],[{"start":1,"end":3,"cssClass":"pl-k"},{"start":5,"end":9,"cssClass":"pl-s1"},{"start":10,"end":12,"cssClass":"pl-c1"},{"start":13,"end":17,"cssClass":"pl-c1"}],[],[{"start":2,"end":6,"cssClass":"pl-en"},{"start":7,"end":13,"cssClass":"pl-s1"}],[{"start":2,"end":8,"cssClass":"pl-k"},{"start":10,"end":15,"cssClass":"pl-s1"}],[],[],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":12,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":9,"cssClass":"pl-c1"}],[],[{"start":1,"end":6,"cssClass":"pl-k"},{"start":8,"end":12,"cssClass":"pl-s1"},{"start":13,"end":15,"cssClass":"pl-c1"},{"start":16,"end":20,"cssClass":"pl-c1"}],[],[{"start":2,"end":6,"cssClass":"pl-s1"},{"start":7,"end":9,"cssClass":"pl-c1"},{"start":11,"end":15,"cssClass":"pl-s1"},{"start":15,"end":17,"cssClass":"pl-c1"},{"start":17,"end":24,"cssClass":"pl-c1"},{"start":25,"end":26,"cssClass":"pl-c1"},{"start":27,"end":31,"cssClass":"pl-s1"},{"start":31,"end":33,"cssClass":"pl-c1"},{"start":33,"end":40,"cssClass":"pl-c1"}],[{"start":2,"end":6,"cssClass":"pl-s1"},{"start":7,"end":8,"cssClass":"pl-c1"},{"start":9,"end":13,"cssClass":"pl-s1"},{"start":13,"end":15,"cssClass":"pl-c1"},{"start":15,"end":19,"cssClass":"pl-c1"}],[],[],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":8,"cssClass":"pl-c1"},{"start":9,"end":13,"cssClass":"pl-s1"}],[],[{"start":1,"end":10,"cssClass":"pl-s1"},{"start":11,"end":12,"cssClass":"pl-c1"},{"start":13,"end":19,"cssClass":"pl-en"},{"start":20,"end":26,"cssClass":"pl-k"},{"start":27,"end":31,"cssClass":"pl-smi"},{"start":33,"end":34,"cssClass":"pl-c1"},{"start":36,"end":40,"cssClass":"pl-s1"},{"start":41,"end":42,"cssClass":"pl-c1"},{"start":43,"end":44,"cssClass":"pl-c1"}],[{"start":1,"end":10,"cssClass":"pl-s1"},{"start":11,"end":15,"cssClass":"pl-s1"},{"start":17,"end":18,"cssClass":"pl-c1"},{"start":19,"end":23,"cssClass":"pl-c1"}],[],[{"start":1,"end":10,"cssClass":"pl-s1"},{"start":11,"end":12,"cssClass":"pl-c1"},{"start":13,"end":27,"cssClass":"pl-en"},{"start":28,"end":29,"cssClass":"pl-c1"},{"start":29,"end":33,"cssClass":"pl-s1"},{"start":35,"end":40,"cssClass":"pl-s1"},{"start":42,"end":51,"cssClass":"pl-s1"},{"start":53,"end":57,"cssClass":"pl-s1"}],[],[{"start":1,"end":5,"cssClass":"pl-en"},{"start":6,"end":11,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-en"},{"start":6,"end":12,"cssClass":"pl-s1"}],[{"start":1,"end":15,"cssClass":"pl-en"},{"start":16,"end":17,"cssClass":"pl-c1"},{"start":17,"end":21,"cssClass":"pl-s1"}],[],[{"start":1,"end":7,"cssClass":"pl-k"},{"start":9,"end":18,"cssClass":"pl-s1"}],[]],"csv":null,"csvError":null,"dependabotInfo":{"showConfigurationBanner":false,"configFilePath":null,"networkDependabotPath":"/luischaparroc/simple_shell/network/updates","dismissConfigurationNoticePath":"/settings/dismiss-notice/dependabot_configuration_notice","configurationNoticeDismissed":null,"repoAlertsPath":"/luischaparroc/simple_shell/security/dependabot","repoSecurityAndAnalysisPath":"/luischaparroc/simple_shell/settings/security_analysis","repoOwnerIsOrg":false,"currentUserCanAdminRepo":false},"displayName":"rep_var.c","displayUrl":"https://github.com/luischaparroc/simple_shell/blob/082057d3703bdc5800c838c14fb07b3d4b2f3c03/rep_var.c?raw=true","headerInfo":{"blobSize":"3.22 KB","deleteInfo":{"deleteTooltip":"You must be signed in to make or propose changes"},"editInfo":{"editTooltip":"You must be signed in to make or propose changes"},"ghDesktopPath":null,"gitLfsPath":null,"onBranch":false,"shortPath":"8b77752","siteNavLoginPath":"/login?return_to=https%3A%2F%2Fgithub.com%2Fluischaparroc%2Fsimple_shell%2Fblob%2F082057d3703bdc5800c838c14fb07b3d4b2f3c03%2Frep_var.c","isCSV":false,"isRichtext":false,"toc":null,"lineInfo":{"truncatedLoc":"183","truncatedSloc":"160"},"mode":"file"},"image":false,"isCodeownersFile":null,"isPlain":false,"isValidLegacyIssueTemplate":false,"issueTemplateHelpUrl":"https://docs.github.com/articles/about-issue-and-pull-request-templates","issueTemplate":null,"discussionTemplate":null,"language":"C","languageID":41,"large":false,"loggedIn":false,"newDiscussionPath":"/luischaparroc/simple_shell/discussions/new","newIssuePath":"/luischaparroc/simple_shell/issues/new","planSupportInfo":{"repoIsFork":null,"repoOwnedByCurrentUser":null,"requestFullPath":"/luischaparroc/simple_shell/blob/082057d3703bdc5800c838c14fb07b3d4b2f3c03/rep_var.c","showFreeOrgGatedFeatureMessage":null,"showPlanSupportBanner":null,"upgradeDataAttributes":null,"upgradePath":null},"publishBannersInfo":{"dismissActionNoticePath":"/settings/dismiss-notice/publish_action_from_dockerfile","dismissStackNoticePath":"/settings/dismiss-notice/publish_stack_from_file","releasePath":"/luischaparroc/simple_shell/releases/new?marketplace=true","showPublishActionBanner":false,"showPublishStackBanner":false},"renderImageOrRaw":false,"richText":null,"renderedFileInfo":null,"shortPath":null,"tabSize":8,"topBannersInfo":{"overridingGlobalFundingFile":false,"globalPreferredFundingPath":null,"repoOwner":"luischaparroc","repoName":"simple_shell","showInvalidCitationWarning":false,"citationHelpUrl":"https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/creating-a-repository-on-github/about-citation-files","showDependabotConfigurationBanner":false,"actionsOnboardingTip":null},"truncated":false,"viewable":true,"workflowRedirectUrl":null,"symbols":{"timedOut":false,"notAnalyzed":false,"symbols":[{"name":"check_env","kind":"function","identStart":197,"identEnd":206,"extentStart":197,"extentEnd":245,"fullyQualifiedName":"check_env","identUtf16":{"start":{"lineNumber":10,"utf16Col":5},"end":{"lineNumber":10,"utf16Col":14}},"extentUtf16":{"start":{"lineNumber":10,"utf16Col":5},"end":{"lineNumber":10,"utf16Col":53}}},{"name":"check_vars","kind":"function","identStart":967,"identEnd":977,"extentStart":967,"extentEnd":1026,"fullyQualifiedName":"check_vars","identUtf16":{"start":{"lineNumber":52,"utf16Col":4},"end":{"lineNumber":52,"utf16Col":14}},"extentUtf16":{"start":{"lineNumber":52,"utf16Col":4},"end":{"lineNumber":52,"utf16Col":63}}},{"name":"replaced_input","kind":"function","identStart":1892,"identEnd":1906,"extentStart":1892,"extentEnd":1960,"fullyQualifiedName":"replaced_input","identUtf16":{"start":{"lineNumber":94,"utf16Col":6},"end":{"lineNumber":94,"utf16Col":20}},"extentUtf16":{"start":{"lineNumber":94,"utf16Col":6},"end":{"lineNumber":94,"utf16Col":74}}},{"name":"rep_var","kind":"function","identStart":2684,"identEnd":2691,"extentStart":2684,"extentEnd":2724,"fullyQualifiedName":"rep_var","identUtf16":{"start":{"lineNumber":144,"utf16Col":6},"end":{"lineNumber":144,"utf16Col":13}},"extentUtf16":{"start":{"lineNumber":144,"utf16Col":6},"end":{"lineNumber":144,"utf16Col":46}}}]}},"copilotInfo":null,"csrf_tokens":{"/luischaparroc/simple_shell/branches":{"post":"sKzxz8EIR1GOiW-6WqFV1q8Uhr7eRxO23OdmKC6qyWaF38G_8OHxvjBH1wEjda3rMDMfudUFFkbVjsAMNsOpuQ"},"/repos/preferences":{"post":"p__9dCamP7luP3HMEeUlF7XKaCClvlJ0YojQ4apMzDPOI9qi0OY7JAhdon16HVIzIbUay2SCY1xTSGzyrcQfbQ"}}},"title":"simple_shell/rep_var.c at 082057d3703bdc5800c838c14fb07b3d4b2f3c03 · luischaparroc/simple_shell"}