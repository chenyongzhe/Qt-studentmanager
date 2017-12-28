/*
Navicat MySQL Data Transfer

Source Server         : 3232
Source Server Version : 50527
Source Host           : localhost:3306
Source Database       : studentmanager

Target Server Type    : MYSQL
Target Server Version : 50527
File Encoding         : 65001

Date: 2017-08-03 11:50:08
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for admin
-- ----------------------------
DROP TABLE IF EXISTS `admin`;
CREATE TABLE `admin` (
  `id` int(11) NOT NULL DEFAULT '0',
  `username` text,
  `password` text,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of admin
-- ----------------------------
INSERT INTO `admin` VALUES ('1', 'admin', 'admin');
INSERT INTO `admin` VALUES ('2', 'admin2', 'admin2');
INSERT INTO `admin` VALUES ('4', '陈永喆', '5251');

-- ----------------------------
-- Table structure for class
-- ----------------------------
DROP TABLE IF EXISTS `class`;
CREATE TABLE `class` (
  `classid` int(11) DEFAULT NULL,
  `classname` text,
  `major` text,
  `membernum` int(11) DEFAULT NULL,
  `instructor` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of class
-- ----------------------------
INSERT INTO `class` VALUES ('101', '信安163班', '信息安全', '29', '刘凌峰');
INSERT INTO `class` VALUES ('102', '信安161班', '信息安全', '30', '戴萌');
INSERT INTO `class` VALUES ('103', '软工165班', '软件工程', '30', '黄安');

-- ----------------------------
-- Table structure for course
-- ----------------------------
DROP TABLE IF EXISTS `course`;
CREATE TABLE `course` (
  `id` int(11) NOT NULL DEFAULT '0',
  `object` text,
  `teacher` text,
  `coursetime` text,
  `courseaddress` text,
  `period` text,
  `credit` text,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of course
-- ----------------------------
INSERT INTO `course` VALUES ('101', '大物', '黄国庆', '大一下', '软件楼102教室', '56', '4');
INSERT INTO `course` VALUES ('102', '高数', '陈春芳', '大一上', '软件楼307教室', '64', '5');
INSERT INTO `course` VALUES ('103', 'c语言', '刘伯成', '大一上', '软件楼109教室', '64', '3');
INSERT INTO `course` VALUES ('105', 'C++', '刘伯成', '大一下', '软件楼103教室', '56', '4');

-- ----------------------------
-- Table structure for fee
-- ----------------------------
DROP TABLE IF EXISTS `fee`;
CREATE TABLE `fee` (
  `id` bigint(20) DEFAULT NULL,
  `name` text,
  `banji` text,
  `major` text,
  `term` text,
  `fee` text,
  `arrearage` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of fee
-- ----------------------------
INSERT INTO `fee` VALUES ('8001716066', '陈永喆', '信安163班', '信息安全', '大一下', '10000元', '0元');
INSERT INTO `fee` VALUES ('1008', '张勇', '网工162班', '网络工程', '大一上', '5550元', '0元');
INSERT INTO `fee` VALUES ('1000', '张三', '计科162班', '计算机科学与技术', '大一下', '5550元', '0元');

-- ----------------------------
-- Table structure for score
-- ----------------------------
DROP TABLE IF EXISTS `score`;
CREATE TABLE `score` (
  `id` bigint(20) DEFAULT NULL,
  `time` text,
  `object` text,
  `score` text,
  `banji` text,
  `teacher` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of score
-- ----------------------------
INSERT INTO `score` VALUES ('1008', '大一下', '大物', '%0', '%1', '%2');
INSERT INTO `score` VALUES ('1000', '大一上', '高数', '81', '162', '张老师');
INSERT INTO `score` VALUES ('8001716066', '大一上', '高数', '89', '163', '陈春芳');
INSERT INTO `score` VALUES ('8001716066', '大一下', '高数', '100', '163', '陈春芳');
INSERT INTO `score` VALUES ('8001716066', '大一下', '大物', '83', '163', '黄国庆');
INSERT INTO `score` VALUES ('122322', '大一下', '大物', '98', '163', '王明');
INSERT INTO `score` VALUES ('100123', '大一下', '大物', '98', '163', '王明');
INSERT INTO `score` VALUES ('12122', '32324', '3232', '343', '344', '43');

-- ----------------------------
-- Table structure for student
-- ----------------------------
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student` (
  `id` bigint(11) NOT NULL,
  `name` text,
  `sex` text,
  `age` text,
  `major` text,
  `banji` int(11) DEFAULT NULL,
  `address` text,
  `phonenumber` text,
  `beizhu` text,
  `password` text,
  `dormnum` text,
  `bednum` text,
  `award` text,
  `punish` text,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of student
-- ----------------------------
INSERT INTO `student` VALUES ('1000', '张三', '男', '19', '计科', '162', '上海', '15925637846', '学生', '123456', '304', '1', '无', '记过');
INSERT INTO `student` VALUES ('1001', '李四', '男', '18', '软件工程', '164', '南昌', '14667344366', '学生', '245343', '301', '3', '数学竞赛一等奖', '无');
INSERT INTO `student` VALUES ('1004', 'xh', '女', '19', '信息安全', '161', '广东', '18138494848', '学生', '1234567', '207', '5', '运动会跳远第一', '无');
INSERT INTO `student` VALUES ('1007', '王五', '女', '18', '土木工程', '164', '河北', '13545665788', '学生', '13225', '207', '2', '学习积极分子', '无');
INSERT INTO `student` VALUES ('1008', '张勇', '男', '18', '网络工程', '163', '南昌', '15029389209', '学生', '5436555', '301', '4', '先进班干部', '无');
INSERT INTO `student` VALUES ('8001716066', '陈永喆', '男', '19', '信息安全', '163', '赣州', '18170874213', '本人', '5252', '305', '2', '物理竞赛一等奖', '无');
