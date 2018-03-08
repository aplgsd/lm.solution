package lm.solution.console.reflection;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

public class ReflectClassTest {

    private void printFields(Class cl) {

        Field[] fields = cl.getDeclaredFields();

        for (Field f : fields) {

            Class type = f.getType();
            String name = f.getName();

            System.out.print(" ");

            String modifiers = Modifier.toString(f.getModifiers());
            if (modifiers.length() > 0) {
                System.out.print(modifiers + " ");
            }
            System.out.println(type.getName() + " " + name + ";");

        }

    }
    private void printConstructors(Class cl){

        Constructor[] constructors=cl.getDeclaredConstructors();

        for(Constructor c : constructors){

            String name=c.getName();
            System.out.print(" ");
            String modifiers=Modifier.toString(c.getModifiers());
            if(modifiers.length()>0){
                System.out.print(modifiers+" ");
            }
            System.out.print(name+"(");

            // 反射参数
            Class[] paramTypes=c.getParameterTypes();
            for (int j=0; j< paramTypes.length;j++){

                if(j>0){
                    System.out.print(", ");
                }
                System.out.print(paramTypes[j].getName());

            }
            System.out.println(");");

        }

    }
    private void printMethods(Class cl){

        Method[] methods=cl.getDeclaredMethods();

        for(Method m : methods){

            Class retType=m.getReturnType();
            String name=m.getName();
            System.out.print(" ");
            String modifiers=Modifier.toString(m.getModifiers());
            if(modifiers.length()>0){
                System.out.print(modifiers+" ");
            }
            System.out.print(retType.getName()+" "+name+"(");
            Class[] paramTypes=m.getParameterTypes();
            for (int j=0;j<paramTypes.length;j++){
                if(j>0){
                    System.out.print(", ");
                }
                System.out.print(paramTypes[j].getName());
            }
            System.out.println(");");

        }

    }
    /**
     * 利用反射打印出 类：域，方法，构造器
     * */
//    @AopTest
    public void printClassMembers(){

        try {

            //
            String fullName = "java.time.LocalDate";

            //
            Class cl = Class.forName(fullName);
            Class superCl=cl.getSuperclass();

            String modifiers=Modifier.toString(cl.getModifiers());
            if(modifiers.length()>0){
                System.out.print(modifiers+" ");
            }
            System.out.print("Class "+fullName);
            if(superCl!=null
                    && superCl!=Object.class){
                System.out.print(" extends "+superCl.getName());
            }
            System.out.print("\n{\n");
            printConstructors(cl);
            System.out.println();
            printMethods(cl);
            System.out.println();
            printFields(cl);
            System.out.println("}");

        }catch (ClassNotFoundException e){
            e.printStackTrace();
        }

    }

}
