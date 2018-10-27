<%@page import="java.sql.Statement"%>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Connection"%>
<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%!
	Connection conn;
	Statement stmt;
	ResultSet set;
	
	String driver = "oracle.jdbc.driver.OracleDriver";
	String url = "jdbc:oracle:thin:@localhost:1521:xe";
	String uid = "scott";
	String upw = "tiger";
%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>Insert title here</title>
</head>
<body>

	<%
		try {
			Class.forName(driver);
			conn = DriverManager.getConnection(url, uid, upw);
			stmt = conn.createStatement();
			set = stmt.executeQuery("select * from memberforpre");
			
			while (set.next()) {
				String id = set.getString("id");
				String pw = set.getString("pw");
				String name = set.getString("name");
				String phone = set.getString("phone");
				
				out.println("아이디 : " + id + ", 비밀번호 : " + pw + ", 이름 : "+ name + ", 전화번호 : " + phone + "<br />");
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				if (set != null) set.close();
				if (stmt != null) stmt.close();
				if (conn != null) conn.close();				
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
	%>

</body>
</html>