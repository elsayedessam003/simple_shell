{"payload":{"allShortcutsEnabled":false,"fileTree":{"":{"items":[{"name":".gitignore","path":".gitignore","contentType":"file"},{"name":"AUTHORS","path":"AUTHORS","contentType":"file"},{"name":"README.md","path":"README.md","contentType":"file"},{"name":"aux_error1.c","path":"aux_error1.c","contentType":"file"},{"name":"aux_error2.c","path":"aux_error2.c","contentType":"file"},{"name":"aux_help.c","path":"aux_help.c","contentType":"file"},{"name":"aux_help2.c","path":"aux_help2.c","contentType":"file"},{"name":"aux_lists.c","path":"aux_lists.c","contentType":"file"},{"name":"aux_lists2.c","path":"aux_lists2.c","contentType":"file"},{"name":"aux_mem.c","path":"aux_mem.c","contentType":"file"},{"name":"aux_stdlib.c","path":"aux_stdlib.c","contentType":"file"},{"name":"aux_str.c","path":"aux_str.c","contentType":"file"},{"name":"aux_str2.c","path":"aux_str2.c","contentType":"file"},{"name":"aux_str3.c","path":"aux_str3.c","contentType":"file"},{"name":"cd.c","path":"cd.c","contentType":"file"},{"name":"cd_shell.c","path":"cd_shell.c","contentType":"file"},{"name":"check_syntax_error.c","path":"check_syntax_error.c","contentType":"file"},{"name":"cmd_exec.c","path":"cmd_exec.c","contentType":"file"},{"name":"env1.c","path":"env1.c","contentType":"file"},{"name":"env2.c","path":"env2.c","contentType":"file"},{"name":"exec_line.c","path":"exec_line.c","contentType":"file"},{"name":"exit_shell.c","path":"exit_shell.c","contentType":"file"},{"name":"get_builtin.c","path":"get_builtin.c","contentType":"file"},{"name":"get_error.c","path":"get_error.c","contentType":"file"},{"name":"get_help.c","path":"get_help.c","contentType":"file"},{"name":"get_line.c","path":"get_line.c","contentType":"file"},{"name":"get_sigint.c","path":"get_sigint.c","contentType":"file"},{"name":"holberton.h","path":"holberton.h","contentType":"file"},{"name":"main.c","path":"main.c","contentType":"file"},{"name":"man_1_simple_shell","path":"man_1_simple_shell","contentType":"file"},{"name":"read_line.c","path":"read_line.c","contentType":"file"},{"name":"rep_var.c","path":"rep_var.c","contentType":"file"},{"name":"shell_loop.c","path":"shell_loop.c","contentType":"file"},{"name":"split.c","path":"split.c","contentType":"file"}],"totalCount":34}},"fileTreeProcessingTime":5.117191999999999,"foldersToFetch":[],"reducedMotionEnabled":null,"repo":{"id":202782214,"defaultBranch":"master","name":"simple_shell","ownerLogin":"luischaparroc","currentUserCanPush":false,"isFork":false,"isEmpty":false,"createdAt":"2019-08-16T18:48:05.000Z","ownerAvatar":"https://avatars.githubusercontent.com/u/43935218?v=4","public":true,"private":false,"isOrgOwned":false},"symbolsExpanded":false,"treeExpanded":true,"refInfo":{"name":"082057d3703bdc5800c838c14fb07b3d4b2f3c03","listCacheKey":"v0:1565983020.0","canEdit":false,"refType":"tree","currentOid":"082057d3703bdc5800c838c14fb07b3d4b2f3c03"},"path":"get_error.c","currentUser":null,"blob":{"rawLines":["#include \"holberton.h\"","","/**"," * get_error - calls the error according the builtin, syntax or permission"," * @datash: data structure that contains arguments"," * @eval: error value"," * Return: error"," */","int get_error(data_shell *datash, int eval)","{","\tchar *error;","","\tswitch (eval)","\t{","\tcase -1:","\t\terror = error_env(datash);","\t\tbreak;","\tcase 126:","\t\terror = error_path_126(datash);","\t\tbreak;","\tcase 127:","\t\terror = error_not_found(datash);","\t\tbreak;","\tcase 2:","\t\tif (_strcmp(\"exit\", datash->args[0]) == 0)","\t\t\terror = error_exit_shell(datash);","\t\telse if (_strcmp(\"cd\", datash->args[0]) == 0)","\t\t\terror = error_get_cd(datash);","\t\tbreak;","\t}","","\tif (error)","\t{","\t\twrite(STDERR_FILENO, error, _strlen(error));","\t\tfree(error);","\t}","","\tdatash->status = eval;","\treturn (eval);","}"],"stylingDirectives":[[{"start":0,"end":8,"cssClass":"pl-k"},{"start":9,"end":22,"cssClass":"pl-s"}],[],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":74,"cssClass":"pl-c"}],[{"start":0,"end":50,"cssClass":"pl-c"}],[{"start":0,"end":21,"cssClass":"pl-c"}],[{"start":0,"end":16,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-c"}],[{"start":0,"end":3,"cssClass":"pl-smi"},{"start":4,"end":13,"cssClass":"pl-en"},{"start":14,"end":24,"cssClass":"pl-smi"},{"start":25,"end":26,"cssClass":"pl-c1"},{"start":26,"end":32,"cssClass":"pl-s1"},{"start":34,"end":37,"cssClass":"pl-smi"},{"start":38,"end":42,"cssClass":"pl-s1"}],[],[{"start":1,"end":5,"cssClass":"pl-smi"},{"start":6,"end":7,"cssClass":"pl-c1"},{"start":7,"end":12,"cssClass":"pl-s1"}],[],[{"start":1,"end":7,"cssClass":"pl-k"},{"start":9,"end":13,"cssClass":"pl-s1"}],[],[{"start":1,"end":5,"cssClass":"pl-k"},{"start":6,"end":8,"cssClass":"pl-c1"}],[{"start":2,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":19,"cssClass":"pl-en"},{"start":20,"end":26,"cssClass":"pl-s1"}],[{"start":2,"end":7,"cssClass":"pl-k"}],[{"start":1,"end":5,"cssClass":"pl-k"},{"start":6,"end":9,"cssClass":"pl-c1"}],[{"start":2,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":24,"cssClass":"pl-en"},{"start":25,"end":31,"cssClass":"pl-s1"}],[{"start":2,"end":7,"cssClass":"pl-k"}],[{"start":1,"end":5,"cssClass":"pl-k"},{"start":6,"end":9,"cssClass":"pl-c1"}],[{"start":2,"end":7,"cssClass":"pl-s1"},{"start":8,"end":9,"cssClass":"pl-c1"},{"start":10,"end":25,"cssClass":"pl-en"},{"start":26,"end":32,"cssClass":"pl-s1"}],[{"start":2,"end":7,"cssClass":"pl-k"}],[{"start":1,"end":5,"cssClass":"pl-k"},{"start":6,"end":7,"cssClass":"pl-c1"}],[{"start":2,"end":4,"cssClass":"pl-k"},{"start":6,"end":13,"cssClass":"pl-en"},{"start":14,"end":20,"cssClass":"pl-s"},{"start":22,"end":28,"cssClass":"pl-s1"},{"start":28,"end":30,"cssClass":"pl-c1"},{"start":30,"end":34,"cssClass":"pl-c1"},{"start":35,"end":36,"cssClass":"pl-c1"},{"start":39,"end":41,"cssClass":"pl-c1"},{"start":42,"end":43,"cssClass":"pl-c1"}],[{"start":3,"end":8,"cssClass":"pl-s1"},{"start":9,"end":10,"cssClass":"pl-c1"},{"start":11,"end":27,"cssClass":"pl-en"},{"start":28,"end":34,"cssClass":"pl-s1"}],[{"start":2,"end":6,"cssClass":"pl-k"},{"start":7,"end":9,"cssClass":"pl-k"},{"start":11,"end":18,"cssClass":"pl-en"},{"start":19,"end":23,"cssClass":"pl-s"},{"start":25,"end":31,"cssClass":"pl-s1"},{"start":31,"end":33,"cssClass":"pl-c1"},{"start":33,"end":37,"cssClass":"pl-c1"},{"start":38,"end":39,"cssClass":"pl-c1"},{"start":42,"end":44,"cssClass":"pl-c1"},{"start":45,"end":46,"cssClass":"pl-c1"}],[{"start":3,"end":8,"cssClass":"pl-s1"},{"start":9,"end":10,"cssClass":"pl-c1"},{"start":11,"end":23,"cssClass":"pl-en"},{"start":24,"end":30,"cssClass":"pl-s1"}],[{"start":2,"end":7,"cssClass":"pl-k"}],[],[],[{"start":1,"end":3,"cssClass":"pl-k"},{"start":5,"end":10,"cssClass":"pl-s1"}],[],[{"start":2,"end":7,"cssClass":"pl-en"},{"start":8,"end":21,"cssClass":"pl-c1"},{"start":23,"end":28,"cssClass":"pl-s1"},{"start":30,"end":37,"cssClass":"pl-en"},{"start":38,"end":43,"cssClass":"pl-s1"}],[{"start":2,"end":6,"cssClass":"pl-en"},{"start":7,"end":12,"cssClass":"pl-s1"}],[],[],[{"start":1,"end":7,"cssClass":"pl-s1"},{"start":7,"end":9,"cssClass":"pl-c1"},{"start":9,"end":15,"cssClass":"pl-c1"},{"start":16,"end":17,"cssClass":"pl-c1"},{"start":18,"end":22,"cssClass":"pl-s1"}],[{"start":1,"end":7,"cssClass":"pl-k"},{"start":9,"end":13,"cssClass":"pl-s1"}],[]],"csv":null,"csvError":null,"dependabotInfo":{"showConfigurationBanner":false,"configFilePath":null,"networkDependabotPath":"/luischaparroc/simple_shell/network/updates","dismissConfigurationNoticePath":"/settings/dismiss-notice/dependabot_configuration_notice","configurationNoticeDismissed":null,"repoAlertsPath":"/luischaparroc/simple_shell/security/dependabot","repoSecurityAndAnalysisPath":"/luischaparroc/simple_shell/settings/security_analysis","repoOwnerIsOrg":false,"currentUserCanAdminRepo":false},"displayName":"get_error.c","displayUrl":"https://github.com/luischaparroc/simple_shell/blob/082057d3703bdc5800c838c14fb07b3d4b2f3c03/get_error.c?raw=true","headerInfo":{"blobSize":"741 Bytes","deleteInfo":{"deleteTooltip":"You must be signed in to make or propose changes"},"editInfo":{"editTooltip":"You must be signed in to make or propose changes"},"ghDesktopPath":null,"gitLfsPath":null,"onBranch":false,"shortPath":"63ba971","siteNavLoginPath":"/login?return_to=https%3A%2F%2Fgithub.com%2Fluischaparroc%2Fsimple_shell%2Fblob%2F082057d3703bdc5800c838c14fb07b3d4b2f3c03%2Fget_error.c","isCSV":false,"isRichtext":false,"toc":null,"lineInfo":{"truncatedLoc":"40","truncatedSloc":"36"},"mode":"executable file"},"image":false,"isCodeownersFile":null,"isPlain":false,"isValidLegacyIssueTemplate":false,"issueTemplateHelpUrl":"https://docs.github.com/articles/about-issue-and-pull-request-templates","issueTemplate":null,"discussionTemplate":null,"language":"C","languageID":41,"large":false,"loggedIn":false,"newDiscussionPath":"/luischaparroc/simple_shell/discussions/new","newIssuePath":"/luischaparroc/simple_shell/issues/new","planSupportInfo":{"repoIsFork":null,"repoOwnedByCurrentUser":null,"requestFullPath":"/luischaparroc/simple_shell/blob/082057d3703bdc5800c838c14fb07b3d4b2f3c03/get_error.c","showFreeOrgGatedFeatureMessage":null,"showPlanSupportBanner":null,"upgradeDataAttributes":null,"upgradePath":null},"publishBannersInfo":{"dismissActionNoticePath":"/settings/dismiss-notice/publish_action_from_dockerfile","dismissStackNoticePath":"/settings/dismiss-notice/publish_stack_from_file","releasePath":"/luischaparroc/simple_shell/releases/new?marketplace=true","showPublishActionBanner":false,"showPublishStackBanner":false},"renderImageOrRaw":false,"richText":null,"renderedFileInfo":null,"shortPath":null,"tabSize":8,"topBannersInfo":{"overridingGlobalFundingFile":false,"globalPreferredFundingPath":null,"repoOwner":"luischaparroc","repoName":"simple_shell","showInvalidCitationWarning":false,"citationHelpUrl":"https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/creating-a-repository-on-github/about-citation-files","showDependabotConfigurationBanner":false,"actionsOnboardingTip":null},"truncated":false,"viewable":true,"workflowRedirectUrl":null,"symbols":{"timedOut":false,"notAnalyzed":false,"symbols":[{"name":"get_error","kind":"function","identStart":201,"identEnd":210,"extentStart":201,"extentEnd":240,"fullyQualifiedName":"get_error","identUtf16":{"start":{"lineNumber":8,"utf16Col":4},"end":{"lineNumber":8,"utf16Col":13}},"extentUtf16":{"start":{"lineNumber":8,"utf16Col":4},"end":{"lineNumber":8,"utf16Col":43}}}]}},"copilotInfo":null,"csrf_tokens":{"/luischaparroc/simple_shell/branches":{"post":"iJdFAYVg7NP3Mv2l7fI45I9zP3ekcRPIE5CGJj8NMOLZ_FYNMAQpvRS4U-wJkG68L0q-U1LKR37yEEsDzsQUag"},"/repos/preferences":{"post":"tWEFroS-uktU4s-PsxU5ONlzlnZ80A-CkeClt-AkVs3-wZAoIz2mQjeB1522wRJWj4JKA4kD8gFOaAd9Ivz5zg"}}},"title":"simple_shell/get_error.c at 082057d3703bdc5800c838c14fb07b3d4b2f3c03 · luischaparroc/simple_shell"}