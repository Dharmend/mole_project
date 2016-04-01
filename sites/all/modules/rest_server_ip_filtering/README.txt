CONTENTS OF THIS FILE
---------------------

 * Overview
 * Installation

Overview
--------
Adds IP filtering authentication to end points created by the services module.

Global IP filtering settings can be set up in the admin at
admin/build/services/rest_ip_filtering, but these settings can be overwritten
on a per end point basis in the authentication screen for the end point.

Dependant modules:
Services
REST Server
Autoload
Chaos tools

Installation
------------
Installing the module is simple:

1) Copy the rest_server_ip_filtering folder to the modules folder in your
   installation.
2) Enable the module using Administer -> Modules (/admin/build/modules)