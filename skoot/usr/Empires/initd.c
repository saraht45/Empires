# include <System.h>
# include <HTTP.h>

inherit module    "/lib/module";

static void
create()
{
   module::create("HTTP");
   /* sequencer::create("/usr/Tool/sys/tool");, */
}

void
boot(int block)
{
   if (ur_name(previous_object()) == MODULED) {
      INFO("Booting Empires...");
   }
}

static void
HTTP_loaded()
{
   HTTPD->register_root("Empires");
}

string
remap_http_request(string root, string url, mapping args)
{
   if (root == "empires") {
      return "/usr/Empires/data/www" + url;
   }
   error("Unknown URL root " + root);
}
