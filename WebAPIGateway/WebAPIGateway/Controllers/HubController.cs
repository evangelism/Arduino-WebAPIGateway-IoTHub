using Microsoft.Azure.Devices.Client;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using System.Web.Http;

namespace WebAPIGateway.Controllers
{
    public class HubController : ApiController
    {

        // GET gw/hub/{...}
        public async Task<HttpResponseMessage> Get(string content)
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("{");
            foreach(var x in Request.GetQueryNameValuePairs())
            {
                if (sb.Length > 2) sb.Append(",");
                sb.Append($"\"{x.Key}\":\"{x.Value}\"");
            }
            sb.Append("}");
            if (content != "secret") throw new Exception("Not authorized");
            var cs = System.Configuration.ConfigurationManager.AppSettings["HubConnectionString"];
            var hub = DeviceClient.CreateFromConnectionString(cs);
            await hub.OpenAsync();
            var msg = new Message(Encoding.UTF8.GetBytes(sb.ToString()));
            await hub.SendEventAsync(msg);
            return new HttpResponseMessage(HttpStatusCode.OK);
        }

        #region "Additional queries..."
        /*
        // GET gw/hub
        public IEnumerable<string> Get()
        {
            return new string[] { "value1", "value2" };
        }


        // POST api/values
        public void Post([FromBody]string value)
        {
        }

        // PUT api/values/5
        public void Put(int id, [FromBody]string value)
        {
        }

        // DELETE api/values/5
        public void Delete(int id)
        {
        }
        */
        #endregion
    }
}
