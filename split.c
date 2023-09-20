{"payload":{"allShortcutsEnabled":false,"fileTree":{"":{"items":[{"name":".gitignore","path":".gitignore","contentType":"file"},{"name":"AUTHORS","path":"AUTHORS","contentType":"file"},{"name":"README.md","path":"README.md","contentType":"file"},{"name":"aux_error1.c","path":"aux_error1.c","contentType":"file"},{"name":"aux_error2.c","path":"aux_error2.c","contentType":"file"},{"name":"aux_help.c","path":"aux_help.c","contentType":"file"},{"name":"aux_help2.c","path":"aux_help2.c","contentType":"file"},{"name":"aux_lists.c","path":"aux_lists.c","contentType":"file"},{"name":"aux_lists2.c","path":"aux_lists2.c","contentType":"file"},{"name":"aux_mem.c","path":"aux_mem.c","contentType":"file"},{"name":"aux_stdlib.c","path":"aux_stdlib.c","contentType":"file"},{"name":"aux_str.c","path":"aux_str.c","contentType":"file"},{"name":"aux_str2.c","path":"aux_str2.c","contentType":"file"},{"name":"aux_str3.c","path":"aux_str3.c","contentType":"file"},{"name":"cd.c","path":"cd.c","contentType":"file"},{"name":"cd_shell.c","path":"cd_shell.c","contentType":"file"},{"name":"check_syntax_error.c","path":"check_syntax_error.c","contentType":"file"},{"name":"cmd_exec.c","path":"cmd_exec.c","contentType":"file"},{"name":"env1.c","path":"env1.c","contentType":"file"},{"name":"env2.c","path":"env2.c","contentType":"file"},{"name":"exec_line.c","path":"exec_line.c","contentType":"file"},{"name":"exit_shell.c","path":"exit_shell.c","contentType":"file"},{"name":"get_builtin.c","path":"get_builtin.c","contentType":"file"},{"name":"get_error.c","path":"get_error.c","contentType":"file"},{"name":"get_help.c","path":"get_help.c","contentType":"file"},{"name":"get_line.c","path":"get_line.c","contentType":"file"},{"name":"get_sigint.c","path":"get_sigint.c","contentType":"file"},{"name":"holberton.h","path":"holberton.h","contentType":"file"},{"name":"main.c","path":"main.c","contentType":"file"},{"name":"man_1_simple_shell","path":"man_1_simple_shell","contentType":"file"},{"name":"read_line.c","path":"read_line.c","contentType":"file"},{"name":"rep_var.c","path":"rep_var.c","contentType":"file"},{"name":"shell_loop.c","path":"shell_loop.c","contentType":"file"},{"name":"split.c","path":"split.c","contentType":"file"}],"totalCount":34}},"fileTreeProcessingTime":3.979364,"foldersToFetch":[],"reducedMotionEnabled":null,"repo":{"id":202782214,"defaultBranch":"master","name":"simple_shell","ownerLogin":"luischaparroc","currentUserCanPush":false,"isFork":false,"isEmpty":false,"createdAt":"2019-08-16T18:48:05.000Z","ownerAvatar":"https://avatars.githubusercontent.com/u/43935218?v=4","public":true,"private":false,"isOrgOwned":false},"symbolsExpanded":false,"treeExpanded":true,"refInfo":{"name":"082057d3703bdc5800c838c14fb07b3d4b2f3c03","listCacheKey":"v0:1565983020.0","canEdit":false,"refType":"tree","currentOid":"082057d3703bdc5800c838c14fb07b3d4b2f3c03"},"path":"split.c","currentUser":null,"blob":{"rawLines":["#include \"holberton.h\"","","/**"," * swap_char - swaps | and & for non-printed chars"," *"," * @input: input string"," * @bool: type of swap"," * Return: swapped string"," */","char *swap_char(char *input, int bool)","{","\tint i;","","\tif (bool == 0)","\t{","\t\tfor (i = 0; input[i]; i++)","\t\t{","\t\t\tif (input[i] == '|')","\t\t\t{","\t\t\t\tif (input[i + 1] != '|')","\t\t\t\t\tinput[i] = 16;","\t\t\t\telse","\t\t\t\t\ti++;","\t\t\t}","","\t\t\tif (input[i] == '&')","\t\t\t{","\t\t\t\tif (input[i + 1] != '&')","\t\t\t\t\tinput[i] = 12;","\t\t\t\telse","\t\t\t\t\ti++;","\t\t\t}","\t\t}","\t}","\telse","\t{","\t\tfor (i = 0; input[i]; i++)","\t\t{","\t\t\tinput[i] = (input[i] == 16 ? '|' : input[i]);","\t\t\tinput[i] = (input[i] == 12 ? '&' : input[i]);","\t\t}","\t}","\treturn (input);","}","","/**"," * add_nodes - add separators and command lines in the lists"," *"," * @head_s: head of separator list"," * @head_l: head of command lines list"," * @input: input string"," * Return: no return"," */","void add_nodes(sep_list **head_s, line_list **head_l, char *input)","{","\tint i;","\tchar *line;","","\tinput = swap_char(input, 0);","","\tfor (i = 0; input[i]; i++)","\t{","\t\tif (input[i] == ';')","\t\t\tadd_sep_node_end(head_s, input[i]);","","\t\tif (input[i] == '|' || input[i] == '&')","\t\t{","\t\t\tadd_sep_node_end(head_s, input[i]);","\t\t\ti++;","\t\t}","\t}","","\tline = _strtok(input, \";|&\");","\tdo {","\t\tline = swap_char(line, 1);","\t\tadd_line_node_end(head_l, line);","\t\tline = _strtok(NULL, \";|&\");","\t} while (line != NULL);","","}","","/**"," * go_next - go to the next command line stored"," *"," * @list_s: separator list"," * @list_l: command line list"," * @datash: data structure"," * Return: no return"," */","void go_next(sep_list **list_s, line_list **list_l, data_shell *datash)","{","\tint loop_sep;","\tsep_list *ls_s;","\tline_list *ls_l;","","\tloop_sep = 1;","\tls_s = *list_s;","\tls_l = *list_l;","","\twhile (ls_s != NULL && loop_sep)","\t{","\t\tif (datash->status == 0)","\t\t{","\t\t\tif (ls_s->separator == '&' || ls_s->separator == ';')","\t\t\t\tloop_sep = 0;","\t\t\tif (ls_s->separator == '|')","\t\t\t\tls_l = ls_l->next, ls_s = ls_s->next;","\t\t}","\t\telse","\t\t{","\t\t\tif (ls_s->separator == '|' || ls_s->separator == ';')","\t\t\t\tloop_sep = 0;","\t\t\tif (ls_s->separator == '&')","\t\t\t\tls_l = ls_l->next, ls_s = ls_s->next;","\t\t}","\t\tif (ls_s != NULL && !loop_sep)","\t\t\tls_s = ls_s->next;","\t}","","\t*list_s = ls_s;","\t*list_l = ls_l;","}","","/**"," * split_commands - splits command lines according to"," * the separators ;, | and &, and executes them"," *"," * @datash: data structure"," * @input: input string"," * Return: 0 to exit, 1 to continue"," */","int split_commands(data_shell *datash, char *input)","{","","\tsep_list *head_s, *list_s;","\tline_list *head_l, *list_l;","\tint loop;","","\thead_s = NULL;","\thead_l = NULL;","","\tadd_nodes(&head_s, &head_l, input);","","\tlist_s = head_s;","\tlist_l = head_l;","","\twhile (list_l != NULL)","\t{","\t\tdatash->input = list_l->line;","\t\tdatash->args = split_line(datash->input);","\t\tloop = exec_line(datash);","\t\tfree(datash->args);","","\t\tif (loop == 0)","\t\t\tbreak;","","\t\tgo_next(&list_s, &list_l, datash);","","\t\tif (list_l != NULL)","\t\t\tlist_l = list_l->next;","\t}","","\tfree_sep_list(&head_s);","\tfree_line_list(&head_l);","","\tif (loop == 0)","\t\treturn (0);","\treturn (1);","}","","/**"," * split_line - tokenizes the input string"," *"," * @input: input string."," * Return: string splitted."," */","char **split_line(char *input)","{","\tsize_t bsize;","\tsize_t i;","\tchar **tokens;","\tchar *token;","","\tbsize = TOK_BUFSIZE;","\ttokens = malloc(sizeof(char *) * (bsize));","\tif (tokens == NULL)","\t{","\t\twrite(STDERR_FILENO, \": allocation error\\n\", 18);","\t\texit(EXIT_FAILURE);","\t}","","\ttoken = _strtok(input, TOK_DELIM);","\ttokens[0] = token;","","\tfor (i = 1; token != NULL; i++)","\t{","\t\tif (i == bsize)","\t\t{","\t\t\tbsize += TOK_BUFSIZE;","\t\t\ttokens = _reallocdp(tokens, i, sizeof(char *) * bsize);","\t\t\tif (tokens == NULL)","\t\t\t{","\t\t\t\twrite(STDERR_FILENO, \": allocation error\\n\", 18);","\t\t\t\texit(EXIT_FAILURE);","\t\t\t}","\t\t}","\t\ttoken = _strtok(NULL, TOK_DELIM);","\t\ttokens[i] = token;","\t}","","\treturn (tokens);","}"],"stylingDirectives":[[{"start":0,"end":8,"cssClass":"pl-k"},{"start":9,"end":22,"cssClass":"pl-s"}],[],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":50,"cssClass":"pl-c"}],[{"start":0,"end":2,"cssClass":"pl-c"}],[{"start":0,"end":23,"cssClass":"pl-c"}],[{"start":0,"end":22,"cssClass":"pl-c"}],[{"start":0,"end":25,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":4,"cssClass":"pl-smi"},{"start":5,"end":6,"cssClass":"pl-c1"},{"start":6,"end":15,"cssClass":"pl-en"},{"start":16,"end":20,"cssClass":"pl-smi"},{"start":21,"end":22,"cssClass":"pl-c1"},{"start":22,"end":27,"cssClass":"pl-s1"},{"start":29,"end":32,"cssClass":"pl-smi"},{"start":33,"end":37,"cssClass":"pl-s1"}],[],[{"start":1,"end":4,"cssClass":"pl-smi"},{"start":5,"end":6,"cssClass":"pl-s1"}],[],[{"start":1,"end":3,"cssClass":"pl-k"},{"start":5,"end":9,"cssClass":"pl-s1"},{"start":10,"end":12,"cssClass":"pl-c1"},{"start":13,"end":14,"cssClass":"pl-c1"}],[],[{"start":2,"end":5,"cssClass":"pl-k"},{"start":7,"end":8,"cssClass":"pl-s1"},{"start":9,"end":10,"cssClass":"pl-c1"},{"start":11,"end":12,"cssClass":"pl-c1"},{"start":14,"end":19,"cssClass":"pl-s1"},{"start":20,"end":21,"cssClass":"pl-s1"},{"start":24,"end":25,"cssClass":"pl-s1"},{"start":25,"end":27,"cssClass":"pl-c1"}],[],[{"start":3,"end":5,"cssClass":"pl-k"},{"start":7,"end":12,"cssClass":"pl-s1"},{"start":13,"end":14,"cssClass":"pl-s1"},{"start":16,"end":18,"cssClass":"pl-c1"},{"start":19,"end":22,"cssClass":"pl-c1"}],[],[{"start":4,"end":6,"cssClass":"pl-k"},{"start":8,"end":13,"cssClass":"pl-s1"},{"start":14,"end":15,"cssClass":"pl-s1"},{"start":16,"end":17,"cssClass":"pl-c1"},{"start":18,"end":19,"cssClass":"pl-c1"},{"start":21,"end":23,"cssClass":"pl-c1"},{"start":24,"end":27,"cssClass":"pl-c1"}],[{"start":5,"end":10,"cssClass":"pl-s1"},{"start":11,"end":12,"cssClass":"pl-s1"},{"start":14,"end":15,"cssClass":"pl-c1"},{"start":16,"end":18,"cssClass":"pl-c1"}],[{"start":4,"end":8,"cssClass":"pl-k"}],[{"start":5,"end":6,"cssClass":"pl-s1"},{"start":6,"end":8,"cssClass":"pl-c1"}],[],[],[{"start":3,"end":5,"cssClass":"pl-k"},{"start":7,"end":12,"cssClass":"pl-s1"},{"start":13,"end":14,"cssClass":"pl-s1"},{"start":16,"end":18,"cssClass":"pl-c1"},{"start":19,"end":22,"cssClass":"pl-c1"}],[],[{"start":4,"end":6,"cssClass":"pl-k"},{"start":8,"end":13,"cssClass":"pl-s1"},{"start":14,"end":15,"cssClass":"pl-s1"},{"start":16,"end":17,"cssClass":"pl-c1"},{"start":18,"end":19,"cssClass":"pl-c1"},{"start":21,"end":23,"cssClass":"pl-c1"},{"start":24,"end":27,"cssClass":"pl-c1"}],[{"start":5,"end":10,"cssClass":"pl-s1"},{"start":11,"end":12,"cssClass":"pl-s1"},{"start":14,"end":15,"cssClass":"pl-c1"},{"start":16,"end":18,"cssClass":"pl-c1"}],[{"start":4,"end":8,"cssClass":"pl-k"}],[{"start":5,"end":6,"cssClass":"pl-s1"},{"start":6,"end":8,"cssClass":"pl-c1"}],[],[],[],[{"start":1,"end":5,"cssClass":"pl-k"}],[],[{"start":2,"end":5,"cssClass":"pl-k"},{"start":7,"end":8,"cssClass":"pl-s1"},{"start":9,"end":10,"cssClass":"pl-c1"},{"start":11,"end":12,"cssClass":"pl-c1"},{"start":14,"end":19,"cssClass":"pl-s1"},{"start":20,"end":21,"cssClass":"pl-s1"},{"start":24,"end":25,"cssClass":"pl-s1"},{"start":25,"end":27,"cssClass":"pl-c1"}],[],[{"start":3,"end":8,"cssClass":"pl-s1"},{"start":9,"end":10,"cssClass":"pl-s1"},{"start":12,"end":13,"cssClass":"pl-c1"},{"start":15,"end":20,"cssClass":"pl-s1"},{"start":21,"end":22,"cssClass":"pl-s1"},{"start":24,"end":26,"cssClass":"pl-c1"},{"start":27,"end":29,"cssClass":"pl-c1"},{"start":32,"end":35,"cssClass":"pl-c1"},{"start":38,"end":43,"cssClass":"pl-s1"},{"start":44,"end":45,"cssClass":"pl-s1"}],[{"start":3,"end":8,"cssClass":"pl-s1"},{"start":9,"end":10,"cssClass":"pl-s1"},{"start":12,"end":13,"cssClass":"pl-c1"},{"start":15,"end":20,"cssClass":"pl-s1"},{"start":21,"end":22,"cssClass":"pl-s1"},{"start":24,"end":26,"cssClass":"pl-c1"},{"start":27,"end":29,"cssClass":"pl-c1"},{"start":32,"end":35,"cssClass":"pl-c1"},{"start":38,"end":43,"cssClass":"pl-s1"},{"start":44,"end":45,"cssClass":"pl-s1"}],[],[],[{"start":1,"end":7,"cssClass":"pl-k"},{"start":9,"end":14,"cssClass":"pl-s1"}],[],[],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":60,"cssClass":"pl-c"}],[{"start":0,"end":2,"cssClass":"pl-c"}],[{"start":0,"end":34,"cssClass":"pl-c"}],[{"start":0,"end":38,"cssClass":"pl-c"}],[{"start":0,"end":23,"cssClass":"pl-c"}],[{"start":0,"end":20,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":4,"cssClass":"pl-smi"},{"start":5,"end":14,"cssClass":"pl-en"},{"start":15,"end":23,"cssClass":"pl-smi"},{"start":24,"end":25,"cssClass":"pl-c1"},{"start":25,"end":26,"cssClass":"pl-c1"},{"start":26,"end":32,"cssClass":"pl-s1"},{"start":34,"end":43,"cssClass":"pl-smi"},{"start":44,"end":45,"cssClass":"pl-c1"},{"start":45,"end":46,"cssClass":"pl-c1"},{"start":46,"end":52,"cssClass":"pl-s1"},{"start":54,"end":58,"cssClass":"pl-smi"},{"start":59,"end":60,"cssClass":"pl-c1"},{"start":60,"end":65,"cssClass":"pl-s1"}],[],[{"start":1,"end":4,"cssClass":"pl-smi"},{"start":5,"end":6,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-smi"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":7,"end":11,"cssClass":"pl-s1"}],[],[{"start":1,"end":6,"cssClass":"pl-s1"},{"start":7,"end":8,"cssClass":"pl-c1"},{"start":9,"end":18,"cssClass":"pl-en"},{"start":19,"end":24,"cssClass":"pl-s1"},{"start":26,"end":27,"cssClass":"pl-c1"}],[],[{"start":1,"end":4,"cssClass":"pl-k"},{"start":6,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":11,"cssClass":"pl-c1"},{"start":13,"end":18,"cssClass":"pl-s1"},{"start":19,"end":20,"cssClass":"pl-s1"},{"start":23,"end":24,"cssClass":"pl-s1"},{"start":24,"end":26,"cssClass":"pl-c1"}],[],[{"start":2,"end":4,"cssClass":"pl-k"},{"start":6,"end":11,"cssClass":"pl-s1"},{"start":12,"end":13,"cssClass":"pl-s1"},{"start":15,"end":17,"cssClass":"pl-c1"},{"start":18,"end":21,"cssClass":"pl-c1"}],[{"start":3,"end":19,"cssClass":"pl-en"},{"start":20,"end":26,"cssClass":"pl-s1"},{"start":28,"end":33,"cssClass":"pl-s1"},{"start":34,"end":35,"cssClass":"pl-s1"}],[],[{"start":2,"end":4,"cssClass":"pl-k"},{"start":6,"end":11,"cssClass":"pl-s1"},{"start":12,"end":13,"cssClass":"pl-s1"},{"start":15,"end":17,"cssClass":"pl-c1"},{"start":18,"end":21,"cssClass":"pl-c1"},{"start":22,"end":24,"cssClass":"pl-c1"},{"start":25,"end":30,"cssClass":"pl-s1"},{"start":31,"end":32,"cssClass":"pl-s1"},{"start":34,"end":36,"cssClass":"pl-c1"},{"start":37,"end":40,"cssClass":"pl-c1"}],[],[{"start":3,"end":19,"cssClass":"pl-en"},{"start":20,"end":26,"cssClass":"pl-s1"},{"start":28,"end":33,"cssClass":"pl-s1"},{"start":34,"end":35,"cssClass":"pl-s1"}],[{"start":3,"end":4,"cssClass":"pl-s1"},{"start":4,"end":6,"cssClass":"pl-c1"}],[],[],[],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":15,"cssClass":"pl-en"},{"start":16,"end":21,"cssClass":"pl-s1"},{"start":23,"end":28,"cssClass":"pl-s"}],[{"start":1,"end":3,"cssClass":"pl-k"}],[{"start":2,"end":6,"cssClass":"pl-s1"},{"start":7,"end":8,"cssClass":"pl-c1"},{"start":9,"end":18,"cssClass":"pl-en"},{"start":19,"end":23,"cssClass":"pl-s1"},{"start":25,"end":26,"cssClass":"pl-c1"}],[{"start":2,"end":19,"cssClass":"pl-en"},{"start":20,"end":26,"cssClass":"pl-s1"},{"start":28,"end":32,"cssClass":"pl-s1"}],[{"start":2,"end":6,"cssClass":"pl-s1"},{"start":7,"end":8,"cssClass":"pl-c1"},{"start":9,"end":16,"cssClass":"pl-en"},{"start":17,"end":21,"cssClass":"pl-c1"},{"start":23,"end":28,"cssClass":"pl-s"}],[{"start":3,"end":8,"cssClass":"pl-k"},{"start":10,"end":14,"cssClass":"pl-s1"},{"start":15,"end":17,"cssClass":"pl-c1"},{"start":18,"end":22,"cssClass":"pl-c1"}],[],[],[],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":47,"cssClass":"pl-c"}],[{"start":0,"end":2,"cssClass":"pl-c"}],[{"start":0,"end":26,"cssClass":"pl-c"}],[{"start":0,"end":29,"cssClass":"pl-c"}],[{"start":0,"end":26,"cssClass":"pl-c"}],[{"start":0,"end":20,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":4,"cssClass":"pl-smi"},{"start":5,"end":12,"cssClass":"pl-en"},{"start":13,"end":21,"cssClass":"pl-smi"},{"start":22,"end":23,"cssClass":"pl-c1"},{"start":23,"end":24,"cssClass":"pl-c1"},{"start":24,"end":30,"cssClass":"pl-s1"},{"start":32,"end":41,"cssClass":"pl-smi"},{"start":42,"end":43,"cssClass":"pl-c1"},{"start":43,"end":44,"cssClass":"pl-c1"},{"start":44,"end":50,"cssClass":"pl-s1"},{"start":52,"end":62,"cssClass":"pl-smi"},{"start":63,"end":64,"cssClass":"pl-c1"},{"start":64,"end":70,"cssClass":"pl-s1"}],[],[{"start":1,"end":4,"cssClass":"pl-smi"},{"start":5,"end":13,"cssClass":"pl-s1"}],[{"start":1,"end":9,"cssClass":"pl-smi"},{"start":10,"end":11,"cssClass":"pl-c1"},{"start":11,"end":15,"cssClass":"pl-s1"}],[{"start":1,"end":10,"cssClass":"pl-smi"},{"start":11,"end":12,"cssClass":"pl-c1"},{"start":12,"end":16,"cssClass":"pl-s1"}],[],[{"start":1,"end":9,"cssClass":"pl-s1"},{"start":10,"end":11,"cssClass":"pl-c1"},{"start":12,"end":13,"cssClass":"pl-c1"}],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":9,"end":15,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":9,"end":15,"cssClass":"pl-s1"}],[],[{"start":1,"end":6,"cssClass":"pl-k"},{"start":8,"end":12,"cssClass":"pl-s1"},{"start":13,"end":15,"cssClass":"pl-c1"},{"start":16,"end":20,"cssClass":"pl-c1"},{"start":21,"end":23,"cssClass":"pl-c1"},{"start":24,"end":32,"cssClass":"pl-s1"}],[],[{"start":2,"end":4,"cssClass":"pl-k"},{"start":6,"end":12,"cssClass":"pl-s1"},{"start":12,"end":14,"cssClass":"pl-c1"},{"start":14,"end":20,"cssClass":"pl-c1"},{"start":21,"end":23,"cssClass":"pl-c1"},{"start":24,"end":25,"cssClass":"pl-c1"}],[],[{"start":3,"end":5,"cssClass":"pl-k"},{"start":7,"end":11,"cssClass":"pl-s1"},{"start":11,"end":13,"cssClass":"pl-c1"},{"start":13,"end":22,"cssClass":"pl-c1"},{"start":23,"end":25,"cssClass":"pl-c1"},{"start":26,"end":29,"cssClass":"pl-c1"},{"start":30,"end":32,"cssClass":"pl-c1"},{"start":33,"end":37,"cssClass":"pl-s1"},{"start":37,"end":39,"cssClass":"pl-c1"},{"start":39,"end":48,"cssClass":"pl-c1"},{"start":49,"end":51,"cssClass":"pl-c1"},{"start":52,"end":55,"cssClass":"pl-c1"}],[{"start":4,"end":12,"cssClass":"pl-s1"},{"start":13,"end":14,"cssClass":"pl-c1"},{"start":15,"end":16,"cssClass":"pl-c1"}],[{"start":3,"end":5,"cssClass":"pl-k"},{"start":7,"end":11,"cssClass":"pl-s1"},{"start":11,"end":13,"cssClass":"pl-c1"},{"start":13,"end":22,"cssClass":"pl-c1"},{"start":23,"end":25,"cssClass":"pl-c1"},{"start":26,"end":29,"cssClass":"pl-c1"}],[{"start":4,"end":8,"cssClass":"pl-s1"},{"start":9,"end":10,"cssClass":"pl-c1"},{"start":11,"end":15,"cssClass":"pl-s1"},{"start":15,"end":17,"cssClass":"pl-c1"},{"start":17,"end":21,"cssClass":"pl-c1"},{"start":23,"end":27,"cssClass":"pl-s1"},{"start":28,"end":29,"cssClass":"pl-c1"},{"start":30,"end":34,"cssClass":"pl-s1"},{"start":34,"end":36,"cssClass":"pl-c1"},{"start":36,"end":40,"cssClass":"pl-c1"}],[],[{"start":2,"end":6,"cssClass":"pl-k"}],[],[{"start":3,"end":5,"cssClass":"pl-k"},{"start":7,"end":11,"cssClass":"pl-s1"},{"start":11,"end":13,"cssClass":"pl-c1"},{"start":13,"end":22,"cssClass":"pl-c1"},{"start":23,"end":25,"cssClass":"pl-c1"},{"start":26,"end":29,"cssClass":"pl-c1"},{"start":30,"end":32,"cssClass":"pl-c1"},{"start":33,"end":37,"cssClass":"pl-s1"},{"start":37,"end":39,"cssClass":"pl-c1"},{"start":39,"end":48,"cssClass":"pl-c1"},{"start":49,"end":51,"cssClass":"pl-c1"},{"start":52,"end":55,"cssClass":"pl-c1"}],[{"start":4,"end":12,"cssClass":"pl-s1"},{"start":13,"end":14,"cssClass":"pl-c1"},{"start":15,"end":16,"cssClass":"pl-c1"}],[{"start":3,"end":5,"cssClass":"pl-k"},{"start":7,"end":11,"cssClass":"pl-s1"},{"start":11,"end":13,"cssClass":"pl-c1"},{"start":13,"end":22,"cssClass":"pl-c1"},{"start":23,"end":25,"cssClass":"pl-c1"},{"start":26,"end":29,"cssClass":"pl-c1"}],[{"start":4,"end":8,"cssClass":"pl-s1"},{"start":9,"end":10,"cssClass":"pl-c1"},{"start":11,"end":15,"cssClass":"pl-s1"},{"start":15,"end":17,"cssClass":"pl-c1"},{"start":17,"end":21,"cssClass":"pl-c1"},{"start":23,"end":27,"cssClass":"pl-s1"},{"start":28,"end":29,"cssClass":"pl-c1"},{"start":30,"end":34,"cssClass":"pl-s1"},{"start":34,"end":36,"cssClass":"pl-c1"},{"start":36,"end":40,"cssClass":"pl-c1"}],[],[{"start":2,"end":4,"cssClass":"pl-k"},{"start":6,"end":10,"cssClass":"pl-s1"},{"start":11,"end":13,"cssClass":"pl-c1"},{"start":14,"end":18,"cssClass":"pl-c1"},{"start":19,"end":21,"cssClass":"pl-c1"},{"start":23,"end":31,"cssClass":"pl-s1"}],[{"start":3,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":14,"cssClass":"pl-s1"},{"start":14,"end":16,"cssClass":"pl-c1"},{"start":16,"end":20,"cssClass":"pl-c1"}],[],[],[{"start":1,"end":2,"cssClass":"pl-c1"},{"start":2,"end":8,"cssClass":"pl-s1"},{"start":9,"end":10,"cssClass":"pl-c1"},{"start":11,"end":15,"cssClass":"pl-s1"}],[{"start":1,"end":2,"cssClass":"pl-c1"},{"start":2,"end":8,"cssClass":"pl-s1"},{"start":9,"end":10,"cssClass":"pl-c1"},{"start":11,"end":15,"cssClass":"pl-s1"}],[],[],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":53,"cssClass":"pl-c"}],[{"start":0,"end":47,"cssClass":"pl-c"}],[{"start":0,"end":2,"cssClass":"pl-c"}],[{"start":0,"end":26,"cssClass":"pl-c"}],[{"start":0,"end":23,"cssClass":"pl-c"}],[{"start":0,"end":35,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-smi"},{"start":4,"end":18,"cssClass":"pl-en"},{"start":19,"end":29,"cssClass":"pl-smi"},{"start":30,"end":31,"cssClass":"pl-c1"},{"start":31,"end":37,"cssClass":"pl-s1"},{"start":39,"end":43,"cssClass":"pl-smi"},{"start":44,"end":45,"cssClass":"pl-c1"},{"start":45,"end":50,"cssClass":"pl-s1"}],[],[],[{"start":1,"end":9,"cssClass":"pl-smi"},{"start":10,"end":11,"cssClass":"pl-c1"},{"start":11,"end":17,"cssClass":"pl-s1"},{"start":19,"end":20,"cssClass":"pl-c1"},{"start":20,"end":26,"cssClass":"pl-s1"}],[{"start":1,"end":10,"cssClass":"pl-smi"},{"start":11,"end":12,"cssClass":"pl-c1"},{"start":12,"end":18,"cssClass":"pl-s1"},{"start":20,"end":21,"cssClass":"pl-c1"},{"start":21,"end":27,"cssClass":"pl-s1"}],[{"start":1,"end":4,"cssClass":"pl-smi"},{"start":5,"end":9,"cssClass":"pl-s1"}],[],[{"start":1,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":14,"cssClass":"pl-c1"}],[{"start":1,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":14,"cssClass":"pl-c1"}],[],[{"start":1,"end":10,"cssClass":"pl-en"},{"start":11,"end":12,"cssClass":"pl-c1"},{"start":12,"end":18,"cssClass":"pl-s1"},{"start":20,"end":21,"cssClass":"pl-c1"},{"start":21,"end":27,"cssClass":"pl-s1"},{"start":29,"end":34,"cssClass":"pl-s1"}],[],[{"start":1,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":16,"cssClass":"pl-s1"}],[{"start":1,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":16,"cssClass":"pl-s1"}],[],[{"start":1,"end":6,"cssClass":"pl-k"},{"start":8,"end":14,"cssClass":"pl-s1"},{"start":15,"end":17,"cssClass":"pl-c1"},{"start":18,"end":22,"cssClass":"pl-c1"}],[],[{"start":2,"end":8,"cssClass":"pl-s1"},{"start":8,"end":10,"cssClass":"pl-c1"},{"start":10,"end":15,"cssClass":"pl-c1"},{"start":16,"end":17,"cssClass":"pl-c1"},{"start":18,"end":24,"cssClass":"pl-s1"},{"start":24,"end":26,"cssClass":"pl-c1"},{"start":26,"end":30,"cssClass":"pl-c1"}],[{"start":2,"end":8,"cssClass":"pl-s1"},{"start":8,"end":10,"cssClass":"pl-c1"},{"start":10,"end":14,"cssClass":"pl-c1"},{"start":15,"end":16,"cssClass":"pl-c1"},{"start":17,"end":27,"cssClass":"pl-en"},{"start":28,"end":34,"cssClass":"pl-s1"},{"start":34,"end":36,"cssClass":"pl-c1"},{"start":36,"end":41,"cssClass":"pl-c1"}],[{"start":2,"end":6,"cssClass":"pl-s1"},{"start":7,"end":8,"cssClass":"pl-c1"},{"start":9,"end":18,"cssClass":"pl-en"},{"start":19,"end":25,"cssClass":"pl-s1"}],[{"start":2,"end":6,"cssClass":"pl-en"},{"start":7,"end":13,"cssClass":"pl-s1"},{"start":13,"end":15,"cssClass":"pl-c1"},{"start":15,"end":19,"cssClass":"pl-c1"}],[],[{"start":2,"end":4,"cssClass":"pl-k"},{"start":6,"end":10,"cssClass":"pl-s1"},{"start":11,"end":13,"cssClass":"pl-c1"},{"start":14,"end":15,"cssClass":"pl-c1"}],[{"start":3,"end":8,"cssClass":"pl-k"}],[],[{"start":2,"end":9,"cssClass":"pl-en"},{"start":10,"end":11,"cssClass":"pl-c1"},{"start":11,"end":17,"cssClass":"pl-s1"},{"start":19,"end":20,"cssClass":"pl-c1"},{"start":20,"end":26,"cssClass":"pl-s1"},{"start":28,"end":34,"cssClass":"pl-s1"}],[],[{"start":2,"end":4,"cssClass":"pl-k"},{"start":6,"end":12,"cssClass":"pl-s1"},{"start":13,"end":15,"cssClass":"pl-c1"},{"start":16,"end":20,"cssClass":"pl-c1"}],[{"start":3,"end":9,"cssClass":"pl-s1"},{"start":10,"end":11,"cssClass":"pl-c1"},{"start":12,"end":18,"cssClass":"pl-s1"},{"start":18,"end":20,"cssClass":"pl-c1"},{"start":20,"end":24,"cssClass":"pl-c1"}],[],[],[{"start":1,"end":14,"cssClass":"pl-en"},{"start":15,"end":16,"cssClass":"pl-c1"},{"start":16,"end":22,"cssClass":"pl-s1"}],[{"start":1,"end":15,"cssClass":"pl-en"},{"start":16,"end":17,"cssClass":"pl-c1"},{"start":17,"end":23,"cssClass":"pl-s1"}],[],[{"start":1,"end":3,"cssClass":"pl-k"},{"start":5,"end":9,"cssClass":"pl-s1"},{"start":10,"end":12,"cssClass":"pl-c1"},{"start":13,"end":14,"cssClass":"pl-c1"}],[{"start":2,"end":8,"cssClass":"pl-k"},{"start":10,"end":11,"cssClass":"pl-c1"}],[{"start":1,"end":7,"cssClass":"pl-k"},{"start":9,"end":10,"cssClass":"pl-c1"}],[],[],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":42,"cssClass":"pl-c"}],[{"start":0,"end":2,"cssClass":"pl-c"}],[{"start":0,"end":24,"cssClass":"pl-c"}],[{"start":0,"end":27,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":4,"cssClass":"pl-smi"},{"start":5,"end":6,"cssClass":"pl-c1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":7,"end":17,"cssClass":"pl-en"},{"start":18,"end":22,"cssClass":"pl-smi"},{"start":23,"end":24,"cssClass":"pl-c1"},{"start":24,"end":29,"cssClass":"pl-s1"}],[],[{"start":1,"end":7,"cssClass":"pl-smi"},{"start":8,"end":13,"cssClass":"pl-s1"}],[{"start":1,"end":7,"cssClass":"pl-smi"},{"start":8,"end":9,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-smi"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":7,"end":8,"cssClass":"pl-c1"},{"start":8,"end":14,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-smi"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":7,"end":12,"cssClass":"pl-s1"}],[],[{"start":1,"end":6,"cssClass":"pl-s1"},{"start":7,"end":8,"cssClass":"pl-c1"},{"start":9,"end":20,"cssClass":"pl-c1"}],[{"start":1,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":16,"cssClass":"pl-en"},{"start":17,"end":23,"cssClass":"pl-k"},{"start":24,"end":28,"cssClass":"pl-smi"},{"start":29,"end":30,"cssClass":"pl-c1"},{"start":32,"end":33,"cssClass":"pl-c1"},{"start":35,"end":40,"cssClass":"pl-s1"}],[{"start":1,"end":3,"cssClass":"pl-k"},{"start":5,"end":11,"cssClass":"pl-s1"},{"start":12,"end":14,"cssClass":"pl-c1"},{"start":15,"end":19,"cssClass":"pl-c1"}],[],[{"start":2,"end":7,"cssClass":"pl-en"},{"start":8,"end":21,"cssClass":"pl-c1"},{"start":23,"end":45,"cssClass":"pl-s"},{"start":47,"end":49,"cssClass":"pl-c1"}],[{"start":2,"end":6,"cssClass":"pl-en"},{"start":7,"end":19,"cssClass":"pl-c1"}],[],[],[{"start":1,"end":6,"cssClass":"pl-s1"},{"start":7,"end":8,"cssClass":"pl-c1"},{"start":9,"end":16,"cssClass":"pl-en"},{"start":17,"end":22,"cssClass":"pl-s1"},{"start":24,"end":33,"cssClass":"pl-c1"}],[{"start":1,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":11,"end":12,"cssClass":"pl-c1"},{"start":13,"end":18,"cssClass":"pl-s1"}],[],[{"start":1,"end":4,"cssClass":"pl-k"},{"start":6,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":11,"cssClass":"pl-c1"},{"start":13,"end":18,"cssClass":"pl-s1"},{"start":19,"end":21,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-c1"},{"start":28,"end":29,"cssClass":"pl-s1"},{"start":29,"end":31,"cssClass":"pl-c1"}],[],[{"start":2,"end":4,"cssClass":"pl-k"},{"start":6,"end":7,"cssClass":"pl-s1"},{"start":8,"end":10,"cssClass":"pl-c1"},{"start":11,"end":16,"cssClass":"pl-s1"}],[],[{"start":3,"end":8,"cssClass":"pl-s1"},{"start":9,"end":11,"cssClass":"pl-c1"},{"start":12,"end":23,"cssClass":"pl-c1"}],[{"start":3,"end":9,"cssClass":"pl-s1"},{"start":10,"end":11,"cssClass":"pl-c1"},{"start":12,"end":22,"cssClass":"pl-en"},{"start":23,"end":29,"cssClass":"pl-s1"},{"start":31,"end":32,"cssClass":"pl-s1"},{"start":34,"end":40,"cssClass":"pl-k"},{"start":41,"end":45,"cssClass":"pl-smi"},{"start":46,"end":47,"cssClass":"pl-c1"},{"start":49,"end":50,"cssClass":"pl-c1"},{"start":51,"end":56,"cssClass":"pl-s1"}],[{"start":3,"end":5,"cssClass":"pl-k"},{"start":7,"end":13,"cssClass":"pl-s1"},{"start":14,"end":16,"cssClass":"pl-c1"},{"start":17,"end":21,"cssClass":"pl-c1"}],[],[{"start":4,"end":9,"cssClass":"pl-en"},{"start":10,"end":23,"cssClass":"pl-c1"},{"start":25,"end":47,"cssClass":"pl-s"},{"start":49,"end":51,"cssClass":"pl-c1"}],[{"start":4,"end":8,"cssClass":"pl-en"},{"start":9,"end":21,"cssClass":"pl-c1"}],[],[],[{"start":2,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":17,"cssClass":"pl-en"},{"start":18,"end":22,"cssClass":"pl-c1"},{"start":24,"end":33,"cssClass":"pl-c1"}],[{"start":2,"end":8,"cssClass":"pl-s1"},{"start":9,"end":10,"cssClass":"pl-s1"},{"start":12,"end":13,"cssClass":"pl-c1"},{"start":14,"end":19,"cssClass":"pl-s1"}],[],[],[{"start":1,"end":7,"cssClass":"pl-k"},{"start":9,"end":15,"cssClass":"pl-s1"}],[]],"csv":null,"csvError":null,"dependabotInfo":{"showConfigurationBanner":false,"configFilePath":null,"networkDependabotPath":"/luischaparroc/simple_shell/network/updates","dismissConfigurationNoticePath":"/settings/dismiss-notice/dependabot_configuration_notice","configurationNoticeDismissed":null,"repoAlertsPath":"/luischaparroc/simple_shell/security/dependabot","repoSecurityAndAnalysisPath":"/luischaparroc/simple_shell/settings/security_analysis","repoOwnerIsOrg":false,"currentUserCanAdminRepo":false},"displayName":"split.c","displayUrl":"https://github.com/luischaparroc/simple_shell/blob/082057d3703bdc5800c838c14fb07b3d4b2f3c03/split.c?raw=true","headerInfo":{"blobSize":"3.6 KB","deleteInfo":{"deleteTooltip":"You must be signed in to make or propose changes"},"editInfo":{"editTooltip":"You must be signed in to make or propose changes"},"ghDesktopPath":null,"gitLfsPath":null,"onBranch":false,"shortPath":"b60b95d","siteNavLoginPath":"/login?return_to=https%3A%2F%2Fgithub.com%2Fluischaparroc%2Fsimple_shell%2Fblob%2F082057d3703bdc5800c838c14fb07b3d4b2f3c03%2Fsplit.c","isCSV":false,"isRichtext":false,"toc":null,"lineInfo":{"truncatedLoc":"212","truncatedSloc":"183"},"mode":"file"},"image":false,"isCodeownersFile":null,"isPlain":false,"isValidLegacyIssueTemplate":false,"issueTemplateHelpUrl":"https://docs.github.com/articles/about-issue-and-pull-request-templates","issueTemplate":null,"discussionTemplate":null,"language":"C","languageID":41,"large":false,"loggedIn":false,"newDiscussionPath":"/luischaparroc/simple_shell/discussions/new","newIssuePath":"/luischaparroc/simple_shell/issues/new","planSupportInfo":{"repoIsFork":null,"repoOwnedByCurrentUser":null,"requestFullPath":"/luischaparroc/simple_shell/blob/082057d3703bdc5800c838c14fb07b3d4b2f3c03/split.c","showFreeOrgGatedFeatureMessage":null,"showPlanSupportBanner":null,"upgradeDataAttributes":null,"upgradePath":null},"publishBannersInfo":{"dismissActionNoticePath":"/settings/dismiss-notice/publish_action_from_dockerfile","dismissStackNoticePath":"/settings/dismiss-notice/publish_stack_from_file","releasePath":"/luischaparroc/simple_shell/releases/new?marketplace=true","showPublishActionBanner":false,"showPublishStackBanner":false},"renderImageOrRaw":false,"richText":null,"renderedFileInfo":null,"shortPath":null,"tabSize":8,"topBannersInfo":{"overridingGlobalFundingFile":false,"globalPreferredFundingPath":null,"repoOwner":"luischaparroc","repoName":"simple_shell","showInvalidCitationWarning":false,"citationHelpUrl":"https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/creating-a-repository-on-github/about-citation-files","showDependabotConfigurationBanner":false,"actionsOnboardingTip":null},"truncated":false,"viewable":true,"workflowRedirectUrl":null,"symbols":{"timedOut":false,"notAnalyzed":false,"symbols":[{"name":"swap_char","kind":"function","identStart":165,"identEnd":174,"extentStart":165,"extentEnd":197,"fullyQualifiedName":"swap_char","identUtf16":{"start":{"lineNumber":9,"utf16Col":6},"end":{"lineNumber":9,"utf16Col":15}},"extentUtf16":{"start":{"lineNumber":9,"utf16Col":6},"end":{"lineNumber":9,"utf16Col":38}}},{"name":"add_nodes","kind":"function","identStart":836,"identEnd":845,"extentStart":836,"extentEnd":897,"fullyQualifiedName":"add_nodes","identUtf16":{"start":{"lineNumber":53,"utf16Col":5},"end":{"lineNumber":53,"utf16Col":14}},"extentUtf16":{"start":{"lineNumber":53,"utf16Col":5},"end":{"lineNumber":53,"utf16Col":66}}},{"name":"go_next","kind":"function","identStart":1478,"identEnd":1485,"extentStart":1478,"extentEnd":1544,"fullyQualifiedName":"go_next","identUtf16":{"start":{"lineNumber":89,"utf16Col":5},"end":{"lineNumber":89,"utf16Col":12}},"extentUtf16":{"start":{"lineNumber":89,"utf16Col":5},"end":{"lineNumber":89,"utf16Col":71}}},{"name":"split_commands","kind":"function","identStart":2331,"identEnd":2345,"extentStart":2331,"extentEnd":2378,"fullyQualifiedName":"split_commands","identUtf16":{"start":{"lineNumber":131,"utf16Col":4},"end":{"lineNumber":131,"utf16Col":18}},"extentUtf16":{"start":{"lineNumber":131,"utf16Col":4},"end":{"lineNumber":131,"utf16Col":51}}},{"name":"split_line","kind":"function","identStart":3043,"identEnd":3053,"extentStart":3043,"extentEnd":3066,"fullyQualifiedName":"split_line","identUtf16":{"start":{"lineNumber":176,"utf16Col":7},"end":{"lineNumber":176,"utf16Col":17}},"extentUtf16":{"start":{"lineNumber":176,"utf16Col":7},"end":{"lineNumber":176,"utf16Col":30}}}]}},"copilotInfo":null,"csrf_tokens":{"/luischaparroc/simple_shell/branches":{"post":"AypizSEsLn11gexO0ha-gO8WKWy0ECv5rD19ur0FHx6_1CiwyJG9Jti1LB68BpHHaI11gYsSJuAE-1sdIyuwLg"},"/repos/preferences":{"post":"C_cSfioxGl5Ndz3p1-TSmN_U5jIUBTDlQRShKRM_u2LAbBo5AgnehUbLY7ZeZn-fZHshjh6c5Dbl3pE0AzxS9A"}}},"title":"simple_shell/split.c at 082057d3703bdc5800c838c14fb07b3d4b2f3c03 · luischaparroc/simple_shell"}