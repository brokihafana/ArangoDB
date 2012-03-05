static string JS_server_modules = 
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief JavaScript server functions\n"
  "///\n"
  "/// @file\n"
  "///\n"
  "/// DISCLAIMER\n"
  "///\n"
  "/// Copyright 2011-2012 triagens GmbH, Cologne, Germany\n"
  "///\n"
  "/// Licensed under the Apache License, Version 2.0 (the \"License\");\n"
  "/// you may not use this file except in compliance with the License.\n"
  "/// You may obtain a copy of the License at\n"
  "///\n"
  "///     http://www.apache.org/licenses/LICENSE-2.0\n"
  "///\n"
  "/// Unless required by applicable law or agreed to in writing, software\n"
  "/// distributed under the License is distributed on an \"AS IS\" BASIS,\n"
  "/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n"
  "/// See the License for the specific language governing permissions and\n"
  "/// limitations under the License.\n"
  "///\n"
  "/// Copyright holder is triAGENS GmbH, Cologne, Germany\n"
  "///\n"
  "/// @author Dr. Frank Celler\n"
  "/// @author Copyright 2011-2012, triAGENS GmbH, Cologne, Germany\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @page JSModuleAvocadoTOC\n"
  "///\n"
  "/// <ol>\n"
  "///   <li>@ref JSModuleAvocadoDefineHttpSystemAction \"avocado.defineHttpSystemAction\"</li>\n"
  "/// </ol>\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @page JSModuleAvocado Module \"avocado\"\n"
  "///\n"
  "/// The following functions are used avocadoly.\n"
  "///\n"
  "/// <hr>\n"
  "/// @copydoc JSModuleAvocadoTOC\n"
  "/// <hr>\n"
  "///\n"
  "/// @anchor JSModuleAvocadoDefineHttpSystemAction\n"
  "/// @copydetails JS_DefineSystemAction\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "// -----------------------------------------------------------------------------\n"
  "// --SECTION--                                                 Module \"internal\"\n"
  "// -----------------------------------------------------------------------------\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @addtogroup V8ModuleInternal\n"
  "/// @{\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief internal module\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "ModuleCache[\"/internal\"].exports.db = db;\n"
  "ModuleCache[\"/internal\"].exports.edges = edges;\n"
  "ModuleCache[\"/internal\"].exports.AvocadoCollection = AvocadoCollection;\n"
  "ModuleCache[\"/internal\"].exports.AvocadoEdgesCollection = AvocadoEdgesCollection;\n"
  "\n"
  "if (typeof SYS_DEFINE_ACTION === \"undefined\") {\n"
  "  ModuleCache[\"/internal\"].exports.defineAction = function() {\n"
  "    console.error(\"SYS_DEFINE_ACTION not available\");\n"
  "  }\n"
  "}\n"
  "else {\n"
  "  ModuleCache[\"/internal\"].exports.defineAction = SYS_DEFINE_ACTION;\n"
  "}\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @}\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "// -----------------------------------------------------------------------------\n"
  "// --SECTION--                                                  Module \"avocado\"\n"
  "// -----------------------------------------------------------------------------\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @addtogroup V8ModuleAvocado\n"
  "/// @{\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @brief avocado module\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "ModuleCache[\"/avocado\"] = new Module(\"/avocado\");\n"
  "\n"
  "if (typeof defineSystemAction == \"function\") {\n"
  "  ModuleCache[\"/avocado\"].exports.defineHttpSystemAction = defineSystemAction;\n"
  "}\n"
  "\n"
  "avocado = ModuleCache[\"/avocado\"].exports;\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @}\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "// -----------------------------------------------------------------------------\n"
  "// --SECTION--                                             Module \"simple-query\"\n"
  "// -----------------------------------------------------------------------------\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @addtogroup V8ModuleSimpleQuery\n"
  "/// @{\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "try {\n"
  "  require(\"simple-query\");\n"
  "}\n"
  "catch (err) {\n"
  "  console.error(\"while loading 'simple-query' module: %s\", err);\n"
  "}\n"
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "/// @}\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  "\n"
  "// Local Variables:\n"
  "// mode: outline-minor\n"
  "// outline-regexp: \"^\\\\(/// @brief\\\\|/// @addtogroup\\\\|// --SECTION--\\\\|/// @page\\\\|/// @}\\\\)\"\n"
  "// End:\n"
;
