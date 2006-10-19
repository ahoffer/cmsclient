/**
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package org.apache.activemq.openwire.tool;

import java.io.File;
import java.io.PrintWriter;

/**
 *
 * @version $Revision: 381410 $
 */
public class AmqCppMarshallingHeadersGenerator extends JavaMarshallingGenerator {

	protected String targetDir="./src/main";

    public Object run() {
        filePostFix = getFilePostFix();
        if (destDir == null) {
            destDir = new File(targetDir+"/activemq/connector/openwire/marshal/v"+getOpenwireVersion());
        }
        return super.run();
    }	   
    
    protected String getFilePostFix() {
        return ".h";
    }
    
    
	protected void generateLicence(PrintWriter out) {
out.println("/*");
out.println(" * Licensed to the Apache Software Foundation (ASF) under one or more");
out.println(" * contributor license agreements.  See the NOTICE file distributed with");
out.println(" * this work for additional information regarding copyright ownership.");
out.println(" * The ASF licenses this file to You under the Apache License, Version 2.0");
out.println(" * (the \"License\"); you may not use this file except in compliance with");
out.println(" * the License.  You may obtain a copy of the License at");
out.println(" *");
out.println(" * http://www.apache.org/licenses/LICENSE-2.0");
out.println(" *");
out.println(" * Unless required by applicable law or agreed to in writing, software");
out.println(" * distributed under the License is distributed on an \"AS IS\" BASIS,");
out.println(" * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.");
out.println(" * See the License for the specific language governing permissions and");
out.println(" * limitations under the License.");
out.println(" */");
	}

	protected void generateFile(PrintWriter out) throws Exception {
		generateLicence(out);
		
out.println("");
out.println("#ifndef _ACTIVEMQ_CONNECTOR_OPENWIRE_MARSAHAL_V"+getOpenwireVersion()+"_"+className.toUpperCase()+"_H_");
out.println("#define _ACTIVEMQ_CONNECTOR_OPENWIRE_MARSAHAL_V"+getOpenwireVersion()+"_"+className.toUpperCase()+"_H_");
out.println("");
out.println("// Turn off warning message for ignored exception specification");
out.println("#ifdef _MSC_VER");
out.println("#pragma warning( disable : 4290 )");
out.println("#endif");
out.println("");
out.println("#include <activemq/connector/openwire/marshal/V"+getOpenwireVersion()+"/"+baseClass+".h>");
out.println("");
out.println("#include <activemq/io/DataInputStream.h>");
out.println("#include <activemq/io/DataOutputStream.h>");
out.println("#include <activemq/io/IOException.h>");
out.println("#include <activemq/connector/openwire/commands/DataStructure.h>");
out.println("#include <activemq/connector/openwire/util/BooleanStream.h>");
out.println("");
out.println("namespace activemq{");
out.println("namespace connector{");
out.println("namespace openwire{");
out.println("namespace marshal{");
out.println("namespace v"+getOpenwireVersion()+"{");
out.println("");
out.println("    /**");
out.println("     * Marshalling code for Open Wire Format for "+className);
out.println("     *");
out.println("     *  NOTE!: This file is autogenerated - do not modify!");
out.println("     *         if you need to make a change, please see the Java Classes");
out.println("     *         in the activemq-openwire-generator module");
out.println("     */");
out.println("    class "+className+" : public "+baseClass);
out.println("    {");
out.println("    public:");
out.println("");
out.println("        "+className+"() {};");
out.println("        virtual ~"+className+"() {};");
out.println("");
out.println("        /**");
out.println("         * Creates a new instance of this marshalable type.");
out.println("         * @return new DataStructure object pointer caller owns it.");
out.println("         */");
out.println("        virtual DataStructure* createObject() const;");
out.println("");
out.println("        /**");
out.println("         * Get the Data Structure Type that identifies this Marshaller");
out.println("         * @return byte holding the data structure type value");
out.println("         */");
out.println("        virtual unsigned char getDataStructureType() const;");
out.println("");
out.println("        /**"); 
out.println("         * Un-marshal an object instance from the data input stream");
out.println("         * @param wireFormat - describs the wire format of the broker");
out.println("         * @param o - Object to be un-marshaled");
out.println("         * @param dataIn - BinaryReader that provides that data");
out.println("         * @param bs - BooleanStream");
out.println("         */"); 
out.println("        virtual void tightUnmarshal( OpenWireFormat* wireFormat,"); 
out.println("                                     commands::DataStructure* dataStructure,"); 
out.println("                                     io::DataInputStream* dataIn,"); 
out.println("                                     util::BooleanStream* bs ) throws( io::IOException );");
out.println("");
out.println("        /**");
out.println("         * Write the booleans that this object uses to a BooleanStream");
out.println("         * @param wireFormat - describis the wire format of the broker");
out.println("         * @param o - Object to be marshaled");
out.println("         * @param bs - BooleanStream");
out.println("         * @returns int");
out.println("         */");
out.println("        virtual int tightMarshal1( OpenWireFormat* wireFormat,"); 
out.println("                                   commands::DataStructure* dataStructure,"); 
out.println("                                   BooleanStream* bs ) throws( io::IOException );");
out.println("");
out.println("        /**");
out.println("         * Write a object instance to data output stream");
out.println("         * @param wireFormat - describs the wire format of the broker");
out.println("         * @param o - Object to be marshaled");
out.println("         * @param dataOut - BinaryReader that provides that data sink");
out.println("         * @param bs - BooleanStream");
out.println("         */");
out.println("        virtual void tightMarshal2( OpenWireFormat* wireFormat,"); 
out.println("                                    commands::DataStructure* dataStructure,"); 
out.println("                                    io::DataOutputStream* dataOut,"); 
out.println("                                    BooleanStream* bs ) throws( io::IOException );");
out.println("");
out.println("        /**"); 
out.println("         * Un-marshal an object instance from the data input stream");
out.println("         * @param wireFormat - describs the wire format of the broker");
out.println("         * @param o - Object to be marshaled");
out.println("         * @param dataIn - BinaryReader that provides that data source");
out.println("         */"); 
out.println("        virtual void looseUnmarshal( OpenWireFormat* wireFormat,"); 
out.println("                                     commands::DataStructure* dataStructure,"); 
out.println("                                     io::DataInputStream* dataIn ) throws( io::IOException );");
out.println("");
out.println("        /**"); 
out.println("         * Write a object instance to data output stream");
out.println("         * @param wireFormat - describs the wire format of the broker");
out.println("         * @param o - Object to be marshaled");
out.println("         * @param dataOut - BinaryWriter that provides that data sink");
out.println("         */");
out.println("        virtual void looseMarshal( OpenWireFormat* wireFormat,"); 
out.println("                                   commands::DataStructure* dataStructure,"); 
out.println("                                   io::DataOutputStream* dataOut ) throws( io::IOException );");
out.println(""); 
out.println("    };");
out.println("");
out.println("}}}}}");
out.println("");
out.println("#endif /*_ACTIVEMQ_CONNECTOR_OPENWIRE_MARSAHAL_V"+getOpenwireVersion()+"_"+className.toUpperCase()+"_H_*/");
out.println("");
        }
 	
    public void generateFactory(PrintWriter out) {
		generateLicence(out);
out.println("#ifndef _ACTIVEMQ_CONNECTOR_OPENWIRE_MARSAHAL_V"+getOpenwireVersion()+"_MARSHALLERFACTORY_H_");
out.println("#define _ACTIVEMQ_CONNECTOR_OPENWIRE_MARSAHAL_V"+getOpenwireVersion()+"_MARSHALLERFACTORY_H_");
out.println("");
out.println("//       Turn off warning message for ignored exception specification");
out.println("#ifdef _MSC_VER");
out.println("#pragma warning( disable : 4290 )");
out.println("#endif");
out.println("");
out.println("#include <activemq/connector/openwire/OpenWireFormat.h>");
out.println("");
out.println("namespace activemq{");
out.println("namespace connector{");
out.println("namespace openwire{");
out.println("namespace marshal{");
out.println("namespace v"+getOpenwireVersion()+"{");
out.println("");
out.println("    /**"); 
out.println("     * Used to create marshallers for a specific version of the wire"); 
out.println("     * protocol.");
out.println("     *");
out.println("     *  NOTE!: This file is autogenerated - do not modify!");
out.println("     *         if you need to make a change, please see the Groovy scripts");
out.println("     *         in the activemq-openwire-generator module");
out.println("     */");
out.println("    class MarshallerFactory");
out.println("    {");
out.println("    public:");
out.println("");
out.println("        virtual ~MarshallerFactory() {};");
out.println("");
out.println("        virtual void configure( OpenWireFormat* format );");
out.println("");
out.println("    };");
out.println("");
out.println("}}}}}");
out.println("");
out.println("#endif /*_ACTIVEMQ_CONNECTOR_OPENWIRE_MARSHAL_V"+getOpenwireVersion()+"_MARSHALLERFACTORY_H_*/");
    }

	public String getTargetDir() {
		return targetDir;
	}

	public void setTargetDir(String targetDir) {
		this.targetDir = targetDir;
	}
}