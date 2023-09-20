{"payload":{"allShortcutsEnabled":false,"fileTree":{"":{"items":[{"name":".gitignore","path":".gitignore","contentType":"file"},{"name":"AUTHORS","path":"AUTHORS","contentType":"file"},{"name":"README.md","path":"README.md","contentType":"file"},{"name":"aux_error1.c","path":"aux_error1.c","contentType":"file"},{"name":"aux_error2.c","path":"aux_error2.c","contentType":"file"},{"name":"aux_help.c","path":"aux_help.c","contentType":"file"},{"name":"aux_help2.c","path":"aux_help2.c","contentType":"file"},{"name":"aux_lists.c","path":"aux_lists.c","contentType":"file"},{"name":"aux_lists2.c","path":"aux_lists2.c","contentType":"file"},{"name":"aux_mem.c","path":"aux_mem.c","contentType":"file"},{"name":"aux_stdlib.c","path":"aux_stdlib.c","contentType":"file"},{"name":"aux_str.c","path":"aux_str.c","contentType":"file"},{"name":"aux_str2.c","path":"aux_str2.c","contentType":"file"},{"name":"aux_str3.c","path":"aux_str3.c","contentType":"file"},{"name":"cd.c","path":"cd.c","contentType":"file"},{"name":"cd_shell.c","path":"cd_shell.c","contentType":"file"},{"name":"check_syntax_error.c","path":"check_syntax_error.c","contentType":"file"},{"name":"cmd_exec.c","path":"cmd_exec.c","contentType":"file"},{"name":"env1.c","path":"env1.c","contentType":"file"},{"name":"env2.c","path":"env2.c","contentType":"file"},{"name":"exec_line.c","path":"exec_line.c","contentType":"file"},{"name":"exit_shell.c","path":"exit_shell.c","contentType":"file"},{"name":"get_builtin.c","path":"get_builtin.c","contentType":"file"},{"name":"get_error.c","path":"get_error.c","contentType":"file"},{"name":"get_help.c","path":"get_help.c","contentType":"file"},{"name":"get_line.c","path":"get_line.c","contentType":"file"},{"name":"get_sigint.c","path":"get_sigint.c","contentType":"file"},{"name":"holberton.h","path":"holberton.h","contentType":"file"},{"name":"main.c","path":"main.c","contentType":"file"},{"name":"man_1_simple_shell","path":"man_1_simple_shell","contentType":"file"},{"name":"read_line.c","path":"read_line.c","contentType":"file"},{"name":"rep_var.c","path":"rep_var.c","contentType":"file"},{"name":"shell_loop.c","path":"shell_loop.c","contentType":"file"},{"name":"split.c","path":"split.c","contentType":"file"}],"totalCount":34}},"fileTreeProcessingTime":4.173167,"foldersToFetch":[],"reducedMotionEnabled":null,"repo":{"id":202782214,"defaultBranch":"master","name":"simple_shell","ownerLogin":"luischaparroc","currentUserCanPush":false,"isFork":false,"isEmpty":false,"createdAt":"2019-08-16T18:48:05.000Z","ownerAvatar":"https://avatars.githubusercontent.com/u/43935218?v=4","public":true,"private":false,"isOrgOwned":false},"symbolsExpanded":false,"treeExpanded":true,"refInfo":{"name":"082057d3703bdc5800c838c14fb07b3d4b2f3c03","listCacheKey":"v0:1565983020.0","canEdit":false,"refType":"tree","currentOid":"082057d3703bdc5800c838c14fb07b3d4b2f3c03"},"path":"aux_help.c","currentUser":null,"blob":{"rawLines":["#include \"holberton.h\"","","/**"," * aux_help_env - Help information for the builtin env"," * Return: no return"," */","void aux_help_env(void)","{","\tchar *help = \"env: env [option] [name=value] [command [args]]\\n\\t\";","","\twrite(STDOUT_FILENO, help, _strlen(help));","\thelp = \"Print the enviroment of the shell.\\n\";","\twrite(STDOUT_FILENO, help, _strlen(help));","","}","/**"," * aux_help_setenv - Help information for the builtin setenv"," * Return: no return"," */","void aux_help_setenv(void)","{","","\tchar *help = \"setenv: setenv (const char *name, const char *value,\";","","\twrite(STDOUT_FILENO, help, _strlen(help));","\thelp = \"int replace)\\n\\t\";","\twrite(STDOUT_FILENO, help, _strlen(help));","\thelp = \"Add a new definition to the environment\\n\";","\twrite(STDOUT_FILENO, help, _strlen(help));","}","/**"," * aux_help_unsetenv - Help information for the builtin unsetenv"," * Return: no return"," */","void aux_help_unsetenv(void)","{","\tchar *help = \"unsetenv: unsetenv (const char *name)\\n\\t\";","","\twrite(STDOUT_FILENO, help, _strlen(help));","\thelp = \"Remove an entry completely from the environment\\n\";","\twrite(STDOUT_FILENO, help, _strlen(help));","}","","","/**"," * aux_help_general - Entry point for help information for the help builtin"," * Return: no return"," */","void aux_help_general(void)","{","\tchar *help = \"^-^ bash, version 1.0(1)-release\\n\";","","\twrite(STDOUT_FILENO, help, _strlen(help));","\thelp = \"These commands are defined internally.Type 'help' to see the list\";","\twrite(STDOUT_FILENO, help, _strlen(help));","\thelp = \"Type 'help name' to find out more about the function 'name'.\\n\\n \";","\twrite(STDOUT_FILENO, help, _strlen(help));","\thelp = \" alias: alias [name=['string']]\\n cd: cd [-L|[-P [-e]] [-@]] \";","\twrite(STDOUT_FILENO, help, _strlen(help));","\thelp = \"[dir]\\nexit: exit [n]\\n  env: env [option] [name=value] [command \";","\twrite(STDOUT_FILENO, help, _strlen(help));","\thelp = \"[args]]\\n  setenv: setenv [variable] [value]\\n  unsetenv: \";","\twrite(STDOUT_FILENO, help, _strlen(help));","\thelp = \"unsetenv [variable]\\n\";","\twrite(STDOUT_FILENO, help, _strlen(help));","}","/**"," * aux_help_exit - Help information fot the builint exit"," * Return: no return"," */","void aux_help_exit(void)","{","\tchar *help = \"exit: exit [n]\\n Exit shell.\\n\";","","\twrite(STDOUT_FILENO, help, _strlen(help));","\thelp = \"Exits the shell with a status of N. If N is ommited, the exit\";","\twrite(STDOUT_FILENO, help, _strlen(help));","\thelp = \"statusis that of the last command executed\\n\";","\twrite(STDOUT_FILENO, help, _strlen(help));","}"],"stylingDirectives":[[{"start":0,"end":8,"cssClass":"pl-k"},{"start":9,"end":22,"cssClass":"pl-s"}],[],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":54,"cssClass":"pl-c"}],[{"start":0,"end":20,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":4,"cssClass":"pl-smi"},{"start":5,"end":17,"cssClass":"pl-en"},{"start":18,"end":22,"cssClass":"pl-smi"}],[],[{"start":1,"end":5,"cssClass":"pl-smi"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":7,"end":11,"cssClass":"pl-s1"},{"start":12,"end":13,"cssClass":"pl-c1"},{"start":14,"end":67,"cssClass":"pl-s"}],[],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":46,"cssClass":"pl-s"}],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[],[],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":60,"cssClass":"pl-c"}],[{"start":0,"end":20,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":4,"cssClass":"pl-smi"},{"start":5,"end":20,"cssClass":"pl-en"},{"start":21,"end":25,"cssClass":"pl-smi"}],[],[],[{"start":1,"end":5,"cssClass":"pl-smi"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":7,"end":11,"cssClass":"pl-s1"},{"start":12,"end":13,"cssClass":"pl-c1"},{"start":14,"end":68,"cssClass":"pl-s"}],[],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":26,"cssClass":"pl-s"}],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":51,"cssClass":"pl-s"}],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":64,"cssClass":"pl-c"}],[{"start":0,"end":20,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":4,"cssClass":"pl-smi"},{"start":5,"end":22,"cssClass":"pl-en"},{"start":23,"end":27,"cssClass":"pl-smi"}],[],[{"start":1,"end":5,"cssClass":"pl-smi"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":7,"end":11,"cssClass":"pl-s1"},{"start":12,"end":13,"cssClass":"pl-c1"},{"start":14,"end":57,"cssClass":"pl-s"}],[],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":59,"cssClass":"pl-s"}],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[],[],[],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":75,"cssClass":"pl-c"}],[{"start":0,"end":20,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":4,"cssClass":"pl-smi"},{"start":5,"end":21,"cssClass":"pl-en"},{"start":22,"end":26,"cssClass":"pl-smi"}],[],[{"start":1,"end":5,"cssClass":"pl-smi"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":7,"end":11,"cssClass":"pl-s1"},{"start":12,"end":13,"cssClass":"pl-c1"},{"start":14,"end":50,"cssClass":"pl-s"}],[],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":75,"cssClass":"pl-s"}],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":75,"cssClass":"pl-s"}],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":71,"cssClass":"pl-s"}],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":75,"cssClass":"pl-s"}],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":68,"cssClass":"pl-s"}],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":31,"cssClass":"pl-s"}],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":56,"cssClass":"pl-c"}],[{"start":0,"end":20,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":4,"cssClass":"pl-smi"},{"start":5,"end":18,"cssClass":"pl-en"},{"start":19,"end":23,"cssClass":"pl-smi"}],[],[{"start":1,"end":5,"cssClass":"pl-smi"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":7,"end":11,"cssClass":"pl-s1"},{"start":12,"end":13,"cssClass":"pl-c1"},{"start":14,"end":46,"cssClass":"pl-s"}],[],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":71,"cssClass":"pl-s"}],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[{"start":1,"end":5,"cssClass":"pl-s1"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":8,"end":54,"cssClass":"pl-s"}],[{"start":1,"end":6,"cssClass":"pl-en"},{"start":7,"end":20,"cssClass":"pl-c1"},{"start":22,"end":26,"cssClass":"pl-s1"},{"start":28,"end":35,"cssClass":"pl-en"},{"start":36,"end":40,"cssClass":"pl-s1"}],[]],"csv":null,"csvError":null,"dependabotInfo":{"showConfigurationBanner":false,"configFilePath":null,"networkDependabotPath":"/luischaparroc/simple_shell/network/updates","dismissConfigurationNoticePath":"/settings/dismiss-notice/dependabot_configuration_notice","configurationNoticeDismissed":null,"repoAlertsPath":"/luischaparroc/simple_shell/security/dependabot","repoSecurityAndAnalysisPath":"/luischaparroc/simple_shell/settings/security_analysis","repoOwnerIsOrg":false,"currentUserCanAdminRepo":false},"displayName":"aux_help.c","displayUrl":"https://github.com/luischaparroc/simple_shell/blob/082057d3703bdc5800c838c14fb07b3d4b2f3c03/aux_help.c?raw=true","headerInfo":{"blobSize":"2.36 KB","deleteInfo":{"deleteTooltip":"You must be signed in to make or propose changes"},"editInfo":{"editTooltip":"You must be signed in to make or propose changes"},"ghDesktopPath":null,"gitLfsPath":null,"onBranch":false,"shortPath":"471b48b","siteNavLoginPath":"/login?return_to=https%3A%2F%2Fgithub.com%2Fluischaparroc%2Fsimple_shell%2Fblob%2F082057d3703bdc5800c838c14fb07b3d4b2f3c03%2Faux_help.c","isCSV":false,"isRichtext":false,"toc":null,"lineInfo":{"truncatedLoc":"80","truncatedSloc":"70"},"mode":"file"},"image":false,"isCodeownersFile":null,"isPlain":false,"isValidLegacyIssueTemplate":false,"issueTemplateHelpUrl":"https://docs.github.com/articles/about-issue-and-pull-request-templates","issueTemplate":null,"discussionTemplate":null,"language":"C","languageID":41,"large":false,"loggedIn":false,"newDiscussionPath":"/luischaparroc/simple_shell/discussions/new","newIssuePath":"/luischaparroc/simple_shell/issues/new","planSupportInfo":{"repoIsFork":null,"repoOwnedByCurrentUser":null,"requestFullPath":"/luischaparroc/simple_shell/blob/082057d3703bdc5800c838c14fb07b3d4b2f3c03/aux_help.c","showFreeOrgGatedFeatureMessage":null,"showPlanSupportBanner":null,"upgradeDataAttributes":null,"upgradePath":null},"publishBannersInfo":{"dismissActionNoticePath":"/settings/dismiss-notice/publish_action_from_dockerfile","dismissStackNoticePath":"/settings/dismiss-notice/publish_stack_from_file","releasePath":"/luischaparroc/simple_shell/releases/new?marketplace=true","showPublishActionBanner":false,"showPublishStackBanner":false},"renderImageOrRaw":false,"richText":null,"renderedFileInfo":null,"shortPath":null,"tabSize":8,"topBannersInfo":{"overridingGlobalFundingFile":false,"globalPreferredFundingPath":null,"repoOwner":"luischaparroc","repoName":"simple_shell","showInvalidCitationWarning":false,"citationHelpUrl":"https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/creating-a-repository-on-github/about-citation-files","showDependabotConfigurationBanner":false,"actionsOnboardingTip":null},"truncated":false,"viewable":true,"workflowRedirectUrl":null,"symbols":{"timedOut":false,"notAnalyzed":false,"symbols":[{"name":"aux_help_env","kind":"function","identStart":113,"identEnd":125,"extentStart":113,"extentEnd":131,"fullyQualifiedName":"aux_help_env","identUtf16":{"start":{"lineNumber":6,"utf16Col":5},"end":{"lineNumber":6,"utf16Col":17}},"extentUtf16":{"start":{"lineNumber":6,"utf16Col":5},"end":{"lineNumber":6,"utf16Col":23}}},{"name":"aux_help_setenv","kind":"function","identStart":438,"identEnd":453,"extentStart":438,"extentEnd":459,"fullyQualifiedName":"aux_help_setenv","identUtf16":{"start":{"lineNumber":19,"utf16Col":5},"end":{"lineNumber":19,"utf16Col":20}},"extentUtf16":{"start":{"lineNumber":19,"utf16Col":5},"end":{"lineNumber":19,"utf16Col":26}}},{"name":"aux_help_unsetenv","kind":"function","identStart":848,"identEnd":865,"extentStart":848,"extentEnd":871,"fullyQualifiedName":"aux_help_unsetenv","identUtf16":{"start":{"lineNumber":34,"utf16Col":5},"end":{"lineNumber":34,"utf16Col":22}},"extentUtf16":{"start":{"lineNumber":34,"utf16Col":5},"end":{"lineNumber":34,"utf16Col":28}}},{"name":"aux_help_general","kind":"function","identStart":1197,"identEnd":1213,"extentStart":1197,"extentEnd":1219,"fullyQualifiedName":"aux_help_general","identUtf16":{"start":{"lineNumber":48,"utf16Col":5},"end":{"lineNumber":48,"utf16Col":21}},"extentUtf16":{"start":{"lineNumber":48,"utf16Col":5},"end":{"lineNumber":48,"utf16Col":27}}},{"name":"aux_help_exit","kind":"function","identStart":2083,"identEnd":2096,"extentStart":2083,"extentEnd":2102,"fullyQualifiedName":"aux_help_exit","identUtf16":{"start":{"lineNumber":70,"utf16Col":5},"end":{"lineNumber":70,"utf16Col":18}},"extentUtf16":{"start":{"lineNumber":70,"utf16Col":5},"end":{"lineNumber":70,"utf16Col":24}}}]}},"copilotInfo":null,"csrf_tokens":{"/luischaparroc/simple_shell/branches":{"post":"uNLcRoKhjRtatxR-zt-2sjdHlDcguEBwmdXBxVrznDqDBeK64tMQt-tlZZxrl-GVlBWzQpGxljeQ34j0Ukh-jQ"},"/repos/preferences":{"post":"K6kza3bOFtNWS6rmyVuKsXX9bFdYBReO6vkjY8_twxkiB3Fp1E72sGGnORYmO8ZixgeICW3MkYppNFRypNHZZA"}}},"title":"simple_shell/aux_help.c at 082057d3703bdc5800c838c14fb07b3d4b2f3c03 · luischaparroc/simple_shell"}