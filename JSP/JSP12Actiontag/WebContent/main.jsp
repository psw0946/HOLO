<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>Insert title here</title>
</head>
<body>
	
	<h1>main.jsp 페이지입니다.</h1>
	
	<jsp:forward page="sub.jsp" />
	<!-- forward는 URL은 변하지 않고 내용만 그 페이지로 변한다. -->
	
</body>
</html>